import pygame
import random
import threading as t
import time
import flask
import keyboard
from flask import jsonify
from flask import Flask, render_template, request
import requests

global gscore
gscore = 0
from pygame import surface

# creating the data structure for pieces
# setting up global vars
# functions
# - create_grid
# - draw_grid
# - draw_window
# - rotating shape in main
# - setting up the main

"""
10 x 20 square grid
shapes: S, Z, I, O, J, L, T
represented in order by 0 - 6
"""
local_ip = '192.168.78.30'
# aws_url = "http://ec2-54-90-26-190.compute-1.amazonaws.com:5000"
aws_url = 'http://ec2-54-87-244-79.compute-1.amazonaws.com:5000'
# aws_url = "http://54.90.26.190:5000"
user_id = ""


def game():
    # GLOBALS VARS
    s_width = 800
    s_height = 700
    play_width = 300  # meaning 300 // 10 = 30 width per block
    play_height = 600  # meaning 600 // 20 = 20 height per block
    block_size = 30

    top_left_x = (s_width - play_width) // 2
    top_left_y = s_height - play_height
    pygame.init()

    pygame.font.init()
    win = pygame.display.set_mode((s_width, s_height))
    pygame.display.set_caption('Tetris')
    # SHAPE FORMATS

    S = [['.....',
          '......',
          '..00..',
          '.00...',
          '.....'],
         ['.....',
          '..0..',
          '..00.',
          '...0.',
          '.....']]

    Z = [['.....',
          '.....',
          '.00..',
          '..00.',
          '.....'],
         ['.....',
          '..0..',
          '.00..',
          '.0...',
          '.....']]

    I = [['..0..',
          '..0..',
          '..0..',
          '..0..',
          '.....'],
         ['.....',
          '0000.',
          '.....',
          '.....',
          '.....']]

    O = [['.....',
          '.....',
          '.00..',
          '.00..',
          '.....']]

    J = [['.....',
          '.0...',
          '.000.',
          '.....',
          '.....'],
         ['.....',
          '..00.',
          '..0..',
          '..0..',
          '.....'],
         ['.....',
          '.....',
          '.000.',
          '...0.',
          '.....'],
         ['.....',
          '..0..',
          '..0..',
          '.00..',
          '.....']]

    L = [['.....',
          '...0.',
          '.000.',
          '.....',
          '.....'],
         ['.....',
          '..0..',
          '..0..',
          '..00.',
          '.....'],
         ['.....',
          '.....',
          '.000.',
          '.0...',
          '.....'],
         ['.....',
          '.00..',
          '..0..',
          '..0..',
          '.....']]

    T = [['.....',
          '..0..',
          '.000.',
          '.....',
          '.....'],
         ['.....',
          '..0..',
          '..00.',
          '..0..',
          '.....'],
         ['.....',
          '.....',
          '.000.',
          '..0..',
          '.....'],
         ['.....',
          '..0..',
          '.00..',
          '..0..',
          '.....']]

    shapes = [S, Z, I, O, J, L, T]
    shape_colors = [(0, 255, 0), (255, 0, 0), (0, 255, 255), (255, 255, 0), (255, 165, 0), (0, 0, 255), (128, 0, 128)]


    # index 0 - 6 represent shape


    class Piece(object):
        rows=20
        colums=10
        def __init__(self,x,y,shape):
            self.x = x
            self.y = y
            self.shape = shape
            self.color = shape_colors[shapes.index(shape)]
            self.rotation = 0




    def create_grid(locked_positions={}):
        grid = [[(0,0,0) for x in range(10)] for x in range(20)]
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if (j,i) in locked_positions:
                    c=locked_positions[(j,i)]
                    grid[i][j]=c
        return grid



    def convert_shape_format(shape):
        positions = []
        format = shape.shape[shape.rotation % len(shape.shape)]

        for i, line in enumerate(format):
            row = list(line)
            for j,column in enumerate(row):
                if column == '0':
                    positions.append((shape.x + j, shape.y + i))

        for i,pos in enumerate(positions):
            positions[i] = (pos[0]-2,pos[1]-4)

        return positions


    import random


    def add_rows(grid, locked, n):
        new_rows=[]
        for i in range(n):
            c_row = []
            choices = [shape_colors,(0,0,0)]
            for j in range(len(grid[0])):
                random_col = random.randint(0,6)
                random_index = random.randint(0, 1)
                choices = [shape_colors[random_col], (0, 0, 0)]
                c_row.append(choices[random_index])
            new_rows.append(c_row)
            # grid.append(new_row)
            # grid.pop(0)


        for key in sorted(list(locked), key=lambda x: x[1]):
                x, y = key
                newKey = (x, y - n)
                locked[newKey] = locked.pop(key)
        for z in range(n):
            for i, val in enumerate(new_rows[z]):
                locked[i,len(grid)-1-z] = val
        return grid, locked


    def valid_space(shape, grid):
        # flatten list
        accepted_positions = [[ (j,i) for j in range(10) if grid[i][j]==(0,0,0)] for i in range(20)]
        accepted_positions = [j for sub in accepted_positions for j in sub]

        formatted=convert_shape_format(shape)
        for pos in formatted:
            if pos not in accepted_positions:
                if pos[1]>-1:
                    return False
        return True


    def check_lost(positions):
        for pos in positions:
            x,y=pos
            if y<1:
                return True
        return False


    def get_shape():

        return Piece(5,0,random.choice(shapes))


    def draw_text_middle(text, size, color, surface):
        font = pygame.font.SysFont("comicsans", size, bold=True)
        label = font.render(text, 1, color)

        surface.blit(label, (
        top_left_x + play_width / 2 - (label.get_width() / 2), top_left_y + play_height / 2 - label.get_height() / 2))



    def draw_grid(surface, grid):

        sx=top_left_x
        sy=top_left_y

        for i in range(len(grid)):
            pygame.draw.line(surface, (128, 128, 128), (sx,sy+i*block_size), (sx+play_width,sy+i*block_size))
            for j in range(len(grid[i])):
                pygame.draw.line(surface, (128, 128, 128), (sx+j*block_size , sy ), (sx + j*block_size, sy +play_height))







    def clear_rows(grid, locked):
        inc=0
        for i in range(len(grid)-1,-1,-1):
            row = grid[i]
            # that means the row is full
            if (0,0,0) not in row:
                inc+=1
                ind=i
                for j in range(len(row)):
                    try:
                        del locked[(j,i)]
                    except:
                        continue

        if inc > 0:
            for key in sorted(list(locked), key=lambda x: x[1])[::-1]:
                x, y = key
                if y < ind:
                    newKey = (x, y + inc)
                    locked[newKey] = locked.pop(key)

        return inc

    def draw_next_shape(shape, surface):
        font=pygame.font.SysFont('comicsans', 30)
        label=font.render('Next Shape', True, (255,255,255))
        sx=top_left_x +play_width + 50
        sy=top_left_y +play_height/2 -100
        format=shape.shape[shape.rotation % len(shape.shape)]

        for i, line in enumerate(format):
            row=list(line)
            for j,column in enumerate(row):
                if column == '0':
                    pygame.draw.rect(surface, shape.color, (sx+j*block_size,sy +i*block_size,block_size,block_size),0)

        surface.blit(label, (sx+10,sy-30))




    def draw_window(surface,grid,score=0):
        surface.fill((0, 0, 0))
        font = pygame.font.SysFont('comi csans', 60)
        label = font.render('Tetris', True, (255, 255, 255))
        surface.blit(label, (top_left_x + play_width / 2 - (label.get_width() / 2), 30))

        font = pygame.font.SysFont('comicsans', 30)
        label = font.render('Score: ' +str(score), True, (255, 255, 255))
        sx = top_left_x + play_width + 50
        sy = top_left_y + play_height / 2 - 100

        surface.blit(label,(sx+20,sy+160))
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                pygame.draw.rect(surface, grid[i][j],
                                 (top_left_x + j * block_size, top_left_y + i * block_size, block_size, block_size), 0)

        draw_grid(surface, grid)
        pygame.draw.rect(surface, (255, 0, 0), (top_left_x, top_left_y, play_width, play_height), 4)

        # pygame.display.update()


    def main(win):
      
        locked_positions = {}
        grid = create_grid(locked_positions)
        changed_piece = False
        run=True
        current_piece = get_shape()
        next_piece = get_shape()
        clock = pygame.time.Clock()
        fall_time=0
        score=0
      

        level_time=0
        while run:
            level_time += clock.get_rawtime()

            if level_time / 1000 > 5:
                level_time = 0
                if level_time > 0.12:
                    level_time -= 0.005
            fall_speed = 0.6
            grid = create_grid(locked_positions)
            fall_time+=clock.get_rawtime()
            clock.tick()
            if fall_time/1000 >fall_speed:
                fall_time=0
                current_piece.y+=1
                if not valid_space(current_piece, grid) and current_piece.y>0:
                    current_piece.y-=1
                    changed_piece=True

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    run = False
                if event.type == pygame.KEYDOWN:

                    if event.key == pygame.K_LEFT:
                        current_piece.x-=1
                        if not(valid_space(current_piece, grid)):
                            current_piece.x+=1

                    if event.key == pygame.K_RIGHT:
                        current_piece.x+=1
                        if not (valid_space(current_piece, grid)):
                            current_piece.x -= 1

                    if event.key == pygame.K_DOWN:
                        while True:
                            current_piece.y+=1
                            if not (valid_space(current_piece, grid)):
                                current_piece.y -= 1
                                break



                    if event.key == pygame.K_d:
                        current_piece.rotation+=1
                        if not (valid_space(current_piece, grid)):
                            current_piece.rotation -= 1

                    if event.key == pygame.K_s:
                        current_piece.rotation-=1
                        if not (valid_space(current_piece, grid)):
                            current_piece.rotation += 1
                        time.sleep(0.2)

                    if event.key == pygame.K_0:
                        r = requests.get(aws_url+"/score?player_id="+user_id+"&score="+str(score))
                        draw_text_middle('You Won!!!!!', 80, (0, 255, 0), win)
                        pygame.display.update()
                        pygame.time.delay(1500)
                        run = False
                    if event.key == pygame.K_1:
                        add_rows(grid, locked_positions, 1)
                    if event.key == pygame.K_2:
                        add_rows(grid, locked_positions, 2)
                    if event.key == pygame.K_3:
                        add_rows(grid, locked_positions, 3)
                    if event.key  == pygame.K_4:
                        add_rows(grid, locked_positions, 4)
                    if event.key == pygame.K_5:
                        add_rows(grid, locked_positions, 5)
                    if event.key == pygame.K_6:
                        add_rows(grid, locked_positions, 6)
                    if event.key == pygame.K_7:
                        add_rows(grid, locked_positions, 7)
                    if event.key == pygame.K_8:
                        add_rows(grid, locked_positions, 8)
                    if event.key == pygame.K_9:
                        add_rows(grid, locked_positions, 9)



            shape_pos=convert_shape_format(current_piece)
            for i in range(len(shape_pos)):
                x,y=shape_pos[i]
                if y>-1:
                    grid[y][x]=current_piece.color
            if changed_piece:
                for pos in shape_pos:
                    p=(pos[0],pos[1])
                    locked_positions[p]=current_piece.color
                current_piece=next_piece
                next_piece=get_shape()
                changed_piece=False
                cleared_rows = clear_rows(grid, locked_positions)
                score+=cleared_rows*10
                global gscore
                gscore = score 
                # print(gscore)
                if cleared_rows != 0:
                    print("sdh")
                    r = requests.get(aws_url+"/lines?add="+str(cleared_rows)+"&player_id="+user_id)
                    cleared_rows=0
                    print("sd")
                else:
                    pass



            draw_window(win,grid,score)
            draw_next_shape(next_piece, win)
            pygame.display.update()

            if check_lost(locked_positions):
                r = requests.get(aws_url+"/loss?player_id="+user_id)
                r = requests.get(aws_url+"/score?player_id="+user_id+"&score="+str(score))
                draw_text_middle('Game Over', 80, (255, 0, 0),win)
                pygame.display.update()
                pygame.time.delay(1500)
                run=False
        pygame.display.quit()



    def main_menu(win):
        main(win)


    main_menu(win)  # start game

def server():
    app = flask.Flask(__name__)

    @app.route('/add_lines', methods=['GET'] )
    def addlines():
        add = request.args.get("add_lines")
        keyboard.send(add)
        return "added line"

    @app.route('/win', methods=['GET'])
    def win():
        keyboard.send("0")
        return "win"

    @app.route('/right')
    def right():
        print("pressed") #debug
        keyboard.send('right')
        return jsonify(str(gscore))
    
    @app.route('/left')
    def left():
        print("pressed") #debug
        keyboard.send('left')
        return jsonify(str(gscore))
    
    @app.route('/drop')
    def drop():
        print("pressed") #debug
        keyboard.send('down')
        return jsonify(str(gscore))

    @app.route('/rright')
    def rright():
        keyboard.send('d')
        return jsonify(str(gscore))

    @app.route('/rleft')
    def rleft():
        keyboard.send('s')
        return jsonify(str(gscore))
    
    @app.route('/score')
    def send_score():
        return jsonify(str(gscore))

    app.run(host=local_ip, port=8080)



def readReq():
    while 1:
        x = requests.get(aws_url+"/read?player_id="+user_id)
        print(x.text)
        if(x.text == "-1"):
            keyboard.send("0") #win

        elif (x.text != "0"):
            keyboard.send(x.text)

        time.sleep(1)


def shit():
    global user_id
    user_id = input("Please enter a username: ")
    r = requests.get(aws_url+"/queue?player_id="+user_id+"&ip="+local_ip)
    t1 = t.Thread(target=server)
    t2 = t.Thread(target=game)
    t3 = t.Thread(target=readReq)
    t3.start()
    t2.start()
    t1.start()



if __name__ == '__main__':
    shit();
