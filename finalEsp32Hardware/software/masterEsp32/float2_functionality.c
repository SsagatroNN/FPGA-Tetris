// #include <stdio.h>
// #include <math.h>
// #include <limits.h>
// #include <altera_avalon_jtag_uart.h>
// #include <altera_avalon_spi.h>
// #include <altera_avalon_spi_regs.h>
// #include <altera_up_avalon_accelerometer_spi.h>
// #include <altera_up_avalon_accelerometer_spi_regs.h>
// #include <sys/alt_irq.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <altera_avalon_pio_regs.h>
// #include "system.h"

// struct node
// {
//     int v;
//     struct node *back;
//     struct node *next;
// };
// typedef struct node node;


// // node* push(node* n)
// // {
// //     node *tmp = malloc(sizeof(node));
// //     if ( n == NULL)
// //     {
// //         n = tmp;
// //         return n;
// //     }
// //     else
// //     {
// //         tmp->back = n;
// //         n->next = tmp;
// //         n = tmp;
// //         return n;
// //     }
// // }

// // node* pop(node *n)
// // {
// //     if (n == NULL)
// //     {
// //         return NULL;
// //     }
// //     else
// //     {
// //         node* tmp;
// //         tmp = n->back;
// //         if (tmp == NULL)
// //         {
// //             free(n);
// //             return NULL;
// //         }
// //         n=n->back;
// //         free(n->next);
// //         return n;
// //     }
// // }

// // node* getTop(node *n)
// // {
// //     return n;
// // }

// // void deallocate(node* n)
// // {
// //     if (n == NULL)
// //     {
// //         return;
// //     }
// //     else
// //     {
// //         while (n != NULL)
// //         {
// //             n = pop(n);
// //         }
// //     }
// // }

// unsigned convertData( int x )
// {
//     if (x == 0)
//     {
//       return 0b1000000;
//     }
//     else if (x == 1)
//     {
//       return 0b1111001;
//     }
//     else if (x == 2)
//     {
//       return 0b0100100;
//     }
//     else if (x == 3)
//     {
//       return 0b0110000;
//     }
//     else if (x == 4)
//     {
//       return 0b00011001;
//     }
//     else if (x == 5)
//     {
//       return 0b0010010;
//     }
//     else if (x == 6)
//     {
//       return 0b0000010;
//     }
//     else if (x == 7)
//     {
//       return 0b1111000;
//     }
//     else if(x == 8)
//     {
//       return 0b0000000;
//     }
//     else if(x == 9)
//     {
//       return 0b0011000;
//     }
//   return 0;
// }

// unsigned parseData(int x)
// {
//     unsigned int rev = 0;
 
//     while (x > 0) {
//         rev <<= 1;
 
//         if ((x & 1) == 1)
//             rev ^= 1;
 
//         x >>= 1;
//     }
//     return rev;
// }

// void writeScore(int s)
// {
//   int arr[6] = {0, 0, 0, 0, 0, 0};
//   for (int i = 0; i < 6; i++)
//   {
//     arr[i] = s%10;
//     s /= 10;
//     if (s == 0)
//     {
//       break;
//     }
//   }
//   IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, convertData(arr[0]));
//   IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE, convertData(arr[1]));
//   IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE, convertData(arr[2]));
//   IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE, convertData(arr[3]));
//   IOWR_ALTERA_AVALON_PIO_DATA(HEX_4_BASE, convertData(arr[4]));
//   IOWR_ALTERA_AVALON_PIO_DATA(HEX_5_BASE, convertData(arr[5]));
// }


// unsigned sendReading ( alt_32 x ) 
// {
//   if ( IORD_ALTERA_AVALON_SPI_STATUS(ESP32_SPI_BASE) && 0b01000000 )
//   {
//     IOWR_ALTERA_AVALON_SPI_TXDATA(ESP32_SPI_BASE, (int) x);
//     // printf("txreg: %d\n", IORD_ALTERA_AVALON_SPI_TXDATA(ESP32_SPI_BASE));
//     // printf("data: %ld\n", (x & 0b111111111));
//   }
//   if ( IORD_ALTERA_AVALON_SPI_STATUS(ESP32_SPI_BASE) && 0b010000000 )
//   {
//     return parseData(IORD_ALTERA_AVALON_SPI_RXDATA(ESP32_SPI_BASE));
//     // printf("txreg: %d\n", IORD_ALTERA_AVALON_SPI_TXDATA(ESP32_SPI_BASE));
//     // printf("data: %ld\n", (x & 0b111111111));
//   }
//   return 0;
// }


// int main()
// {
//   alt_32 x_read, y_read;
//   int buttons;
//   int score = 0;
//   alt_up_accelerometer_spi_dev *accDev;
//   accDev = alt_up_accelerometer_spi_open_dev(ACCELEROMETER_SPI_NAME);

//   if ( accDev == NULL )
//   {
//     return 1;
//   } 

//   while ( 1 )
//   {
//     buttons = (~IORD_ALTERA_AVALON_PIO_DATA(KEYS_0_BASE)) & 0x3;
//     alt_up_accelerometer_spi_read_x_axis(accDev, &x_read);
//     alt_up_accelerometer_spi_read_y_axis(accDev, &y_read);
//     printf("x: %ld, y: %ld, buttons:%d\n", x_read, y_read, buttons);
//     sendReading(((x_read & 0b1111111111) + ((y_read & 0b1111111111) << 9)) + (buttons << 24));
//     // writeScore(score);
//     usleep(1);
//   }
//   printf("Hello from Nios II!\n");

//   return 0;
// }



#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <altera_avalon_jtag_uart.h>
#include <altera_avalon_spi.h>
#include <altera_avalon_spi_regs.h>
#include <altera_up_avalon_accelerometer_spi.h>
#include <altera_up_avalon_accelerometer_spi_regs.h>
#include <sys/alt_irq.h>
#include <unistd.h>
#include <stdlib.h>
#include <altera_avalon_pio_regs.h>
#include "system.h"
#include <FreeRTOSConfig.h>
#include "FreeRTOS.h"
#include "task.h"

int score = 0;

unsigned convertData( int x )
{
    if (x == 0)
    {
      return 0b1000000;
    }
    else if (x == 1)
    {
      return 0b1111001;
    }
    else if (x == 2)
    {
      return 0b0100100;
    }
    else if (x == 3)
    {
      return 0b0110000;
    }
    else if (x == 4)
    {
      return 0b00011001;
    }
    else if (x == 5)
    {
      return 0b0010010;
    }
    else if (x == 6)
    {
      return 0b0000010;
    }
    else if (x == 7)
    {
      return 0b1111000;
    }
    else if(x == 8)
    {
      return 0b0000000;
    }
    else if(x == 9)
    {
      return 0b0011000;
    }
  return 0;
}

uint32_t reversBits(uint32_t n) {
    uint32_t x = 0;
    int d = 0;
    while(n>0){
        x+=(n%2) << (31-d);
        n >>= 1;
        d++;
    }
    return x;
}

void writeScore(int s)
{
  int arr[6] = {0, 0, 0, 0, 0, 0};
  for (int i = 0; i < 6; i++)
  {
    arr[i] = s%10;
    s = s / 10;
    if (s == 0)
    {
      break;
    }
  }
  IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, 0);
  IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE, 0);
  IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE, 0);
  IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE, convertData(arr[3]));
  IOWR_ALTERA_AVALON_PIO_DATA(HEX_4_BASE, convertData(arr[4]));
  IOWR_ALTERA_AVALON_PIO_DATA(HEX_5_BASE, convertData(arr[5]));
  // printf("str: %d\n", s);
}




void sendReading ( alt_32 x ) 
{
  if ( IORD_ALTERA_AVALON_SPI_STATUS(ESP32_SPI_BASE) && 0b01000000 )
  {
    IOWR_ALTERA_AVALON_SPI_TXDATA(ESP32_SPI_BASE, (int) x);
    // printf("txreg: %d\n", IORD_ALTERA_AVALON_SPI_TXDATA(ESP32_SPI_BASE));
    // printf("data: %ld\n", (x & 0b111111111));
  }
}

unsigned getScore ()
{
  if ( IORD_ALTERA_AVALON_SPI_STATUS(ESP32_SPI_BASE) && 0b010000000 )
  {
    return reversBits(IORD_ALTERA_AVALON_SPI_RXDATA(ESP32_SPI_BASE));
    // printf("txreg: %d\n", IORD_ALTERA_AVALON_SPI_TXDATA(ESP32_SPI_BASE));
    // printf("data: %ld\n", (x & 0b111111111));
  }
  // score += 10;
  // return score;
  return 0;
}

void task1()
{

  alt_32 x_read, y_read;
  int buttons;
  alt_up_accelerometer_spi_dev *accDev;
  accDev = alt_up_accelerometer_spi_open_dev(ACCELEROMETER_SPI_NAME);

  if ( accDev == NULL )
  {
    return;
  } 

  while ( 1 )
  {
    buttons = (~IORD_ALTERA_AVALON_PIO_DATA(KEYS_0_BASE)) & 0x3;
    alt_up_accelerometer_spi_read_x_axis(accDev, &x_read);
    alt_up_accelerometer_spi_read_y_axis(accDev, &y_read);
    printf("%ld\n", x_read);
    sendReading(((x_read & 0b1111111111) + ((y_read & 0b1111111111) << 9)) + (buttons << 24));
    vTaskDelay(1);
  }
 
}


void task2()
{
  while (1)
  {
    writeScore(getScore());
    printf("wrote score\n");
    vTaskDelay(5000);
  }
}



int main()
{
  xTaskCreate(task1, "Task 1", 1024, NULL, 1, NULL);
  xTaskCreate(task2, "Task 2", 1024, NULL, 2, NULL);

  vTaskStartScheduler();
  return 0;
}
