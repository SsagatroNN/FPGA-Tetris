#include <Arduino.h>
#include <SPI.h>
#include <ESP32SPISlave.h>
#include <bitset>
#include <type_traits>
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include "ESP_fft.h"
#include <HTTPClient.h>

#define N 32
#define samplingRate 2000

//fft stuff
float in_x[N];
float out_x[N];
float in_y[N];
float out_y[N];

ESP_fft espFFT_x(N, samplingRate, FFT_REAL, FFT_FORWARD, in_x, out_x);
ESP_fft espFFT_y(N, samplingRate, FFT_REAL, FFT_FORWARD, in_y, out_y);

// esp32 slave stuff
ESP32SPISlave slave;
uint8_t spi_slave_tx_buf[4];
uint8_t spi_slave_rx_buf[4];


// esp32 wifi stuff
WiFiClient client;
const char *host = "192.168.78.152";
const int port = 10000;
bool validConnection = 0;
String serverName = "http://192.168.78.152:8080/";

// readings
short x = 0;
int top_x = 0;
short y = 0;
int top_y = 0;
int buttons = 0;


void setup()
{
  // starting wifi
  WiFi.begin("Bruh", "qurs1567");
  while ( WiFi.status() != WL_CONNECTED ) 
  {
    Serial.println("Establishing connection to WiFi..");
    delay(1000);
  }

  // starting slave
  slave.setDataMode(SPI_MODE0);
  slave.begin(VSPI);
  Serial.begin(115200);
  Serial.println("Connected to network");
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // validConnection = client.connect(host, port);
}


void fillArrays(float x, float y)
{
  for (int i = 0; i < N; i++)
  {
    in_x[i] = x;
    in_y[i] = y;
  }
}

void sendRotateRight()
{
  HTTPClient http;
  http.begin(serverName+"rright");
  int httpResponseCode = http.GET();
  std::cout << httpResponseCode << " : right" << std::endl;

}

void sendRotateLeft()
{
  HTTPClient http;
  http.begin(serverName+"rleft");
  int httpResponseCode = http.GET();
  std::cout << "left" << std::endl;
}

void sendDrop()
{
  HTTPClient http;
  http.begin(serverName+"drop");
  int httpResponseCode = http.GET();
  std::cout << "drop" << std::endl;
}

void sendRButton()
{
  HTTPClient http;
  http.begin(serverName+"right");
  int httpResponseCode = http.GET();

}

void sendLButton()
{
  HTTPClient http;
  http.begin(serverName+"left");
  int httpResponseCode = http.GET();
  // std::cout << http.headers() << std::endl;
}

void sendSignal(int avg_x, int avg_y, int butt)
{
  if (std::abs(avg_x) > 8)
  {
    (avg_x > 0) ? sendRotateRight() :  sendRotateLeft(); 
  }
  else if(std::abs(avg_y) < 6)
  {
    sendDrop();
  }
  if (buttons == 1)
  {
    sendLButton();
  }
  else if (buttons == 2)
  {
    sendRButton();
  }
}

int getSgn(int x)
{
  return (x < 0) ? -1 : 1;
}

int getDiff(int x, int y)
{
  return std::abs(x) - std::abs(y);
}

int n = 0;
void loop()
{ 
  slave.wait(spi_slave_rx_buf, spi_slave_tx_buf, 32);


  /*
    SPI is MSB first, thus the data recieved is reversed:
    BUFF[31:0], spi_slave_rx_buf[location][bitnumber]
    Buttons: BUFF[25] + BUFF[24] :: spi_slave_rx_buf[0][1:0] 
    Y-axis acceleration = BUFF[17:9] :: spi_slave_rx_buf[1][1:0] + spi_slave_rx_buf[2][7:1]
    X-axis acceleration = BUFFP[8:0] :: spi_slave_rx_buf[2][0] + spi_slave_rx_buf[3]
  */


  while( slave.available() )
  {
    // bit manipulation fo x 
    x = (spi_slave_rx_buf[3]);
    top_x = (spi_slave_rx_buf[2] & 1);
    x = (top_x) ? (x | 0xff00) : x;

    // bit manipulation to get y
    y = spi_slave_rx_buf[2] >> 1;
    y = ((spi_slave_rx_buf[1] & 1) << 7) | y;
    top_y = (spi_slave_rx_buf[1] & 2);
    y = (top_y) ? (y | 0xff00) : y;

    // bit manipulation to get buttons
    buttons = spi_slave_rx_buf[0];


    slave.pop();
    // delay(100);
  }
  fillArrays(x, y);
  espFFT_x.hammingWindow();
  espFFT_x.execute();
  espFFT_x.removeDC();
  espFFT_x.complexToMagnitude();
  espFFT_y.hammingWindow();
  espFFT_y.execute();
  espFFT_y.removeDC();
  espFFT_y.complexToMagnitude();

  float avg_x = 0;
  float avg_y = 0;

  for (int i = 0; i < N; i++)
  {
    if (i >= 3 && i <= 10)
    {
      avg_x += out_x[i];
      avg_y += out_y[i];
    }
    
  }
  std::cout << avg_y << std::endl;
  // avg /= 2;
  avg_x = avg_x*getSgn(x);
  avg_y = avg_y;

  // std::cout << y << std::endl;
  std::cout << buttons << std::endl;
  sendSignal(avg_x, avg_y, buttons);
  delay(100);
}


/*
  sendSignal()
  {
    check if the range of frequencies ( 5 < f < 10) is high (according to mag), send signal, else dont do shit, also always send button
    // algorithm is inefficient but this should slow it down enough
    if its too slow i multithread
  }
*/;