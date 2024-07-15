#!/usr/bin/env pybricks-micropython
from pybricks.hubs import EV3Brick
from pybricks.ev3devices import (Motor, TouchSensor, ColorSensor,
                                 InfraredSensor, UltrasonicSensor, GyroSensor)
from pybricks.parameters import Port, Stop, Direction, Button, Color
from pybricks.tools import wait, StopWatch, DataLog
from pybricks.robotics import DriveBase
from pybricks.media.ev3dev import SoundFile, ImageFile

ev3 = EV3Brick()

"""
    Prova 1: Completar circuito desenhado se matendo dentro da pista.
    !!! Pode ser melhorado implementando mais detectores se a colisão ocorreu antes !!!
    Alunos: Geilso Faria Rodrigues da Silva 
            Daniel Rocha Rodrigues
"""

#-----Declarações-----
left_motor = Motor(Port.A)
right_motor = Motor(Port.C)
robot = DriveBase(left_motor, right_motor, wheel_diameter=55.5, axle_track=104) 
sensor_cor= ColorSensor(Port.S3)
velocidade = 450
tempo = StopWatch()
contador = 0

#-----R1-----
while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()
left_motor.run_time(-300, 1500, wait=False)
right_motor.run_time(-300, 1500, wait=True)
#-----C1-----
left_motor.run_time(300, 1750, wait=False)
right_motor.run_time(0, 1750, wait=True)

tempo.reset()#Reinicia temporazidor
tempo.time()#Começa a contar
#-----R2------
while contador < 1 and tempo.time() < 5200:
    if tempo.time() < 5200 and sensor_cor.reflection() < 12:
        robot.turn(20)
        robot.stop()
        contador = 1
    else:
        left_motor.run(velocidade)
        right_motor.run(velocidade)

while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)
    
left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 1500, wait=False)
right_motor.run_time(-300, 1500, wait=True)

#-----C2-----
left_motor.run_time(0, 1750, wait=False)
right_motor.run_time(300, 1750, wait=True)

#-----R3-----
#Tempo = 4289
tempo.reset()
contador = 0
while contador < 1 and tempo.time() < 4089:
    if tempo.time() < 4089 and sensor_cor.reflection() < 12:
        left_motor.stop()
        right_motor.stop()
        #robot.turn(30)
        #robot.stop()
        left_motor.run_time(-300, 3500, wait=False)
        right_motor.run_time(-300, 3500, wait=True)
        robot.turn(-30)
        robot.stop()
        left_motor.run_time(velocidade, 750, wait=False)
        right_motor.run_time(velocidade, 750, wait= True)
        contador = 1
    else:
        left_motor.run(velocidade)
        right_motor.run(velocidade)

while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)


left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 1500, wait=False)
right_motor.run_time(-300, 1500, wait=True)

#-----C3-----
left_motor.run_time(0, 1750, wait=False)
right_motor.run_time(300, 1750, wait=True)

#-----R4-----
while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 1500, wait=False)
right_motor.run_time(-300, 1500, wait=True)

#-----C4-----
left_motor.run_time(300, 1850, wait=False)
right_motor.run_time(0, 1850, wait=True)

#-----R5-----
tempo.reset()
contador = 0
while contador < 1 and tempo.time() < 9026:
    if tempo.time() < 9026 and sensor_cor.reflection() < 12:
        robot.turn(20)
        robot.stop()
        contador = 1
    else:
        left_motor.run(velocidade)
        right_motor.run(velocidade)

while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()
left_motor.run_time(-300, 2300, wait=False)
right_motor.run_time(-300, 2300, wait=True)

#-----C5-----
left_motor.run_time(300, 1750, wait=False)
right_motor.run_time(0, 1750, wait=True)

#-----R6-----
#Até o armário
while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 2600, wait=False)
right_motor.run_time(-300, 2600, wait=True)

#-----C6-----
left_motor.run_time(0, 1750, wait=False)#1750 aqui
right_motor.run_time(300, 1750, wait=True)#1750 aqui

#-----R7-----
while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 2100, wait=False)
right_motor.run_time(-300, 2100, wait=True)

#-----C7-----
left_motor.run_time(0, 1200, wait=False)
right_motor.run_time(300, 1200, wait=True)

#-----R8-----

tempo.reset()
while sensor_cor.reflection() > 12:
    tempo.time()
    left_motor.run(velocidade)
    right_motor.run(velocidade)
    tempoR8 = tempo.time() 

left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 2500, wait=False)
right_motor.run_time(-300, 2500, wait=True)

#-----C8-----
left_motor.run_time(300, 2000, wait=False)
right_motor.run_time(0, 2000, wait=True)

#-----R9-----
#Até as costa do armário
#-----------------------
left_motor.run_time(450, 2500, wait=False)
right_motor.run_time(450, 2500, wait= True)

#-----C9-----
# CURVA CURTA
#------------
#Tempo: Certo = 9542 Errado = 12007 
robot.turn(60)
robot.stop()
tempo.reset()
contador = 0

#-----R10-----
while contador < 1 and tempo.time() < 5500:
    if tempo.time() < 5500 and sensor_cor.reflection() < 12:
        left_motor.stop()
        right_motor.stop()
        left_motor.run_time(-300, 1500, wait=False)
        right_motor.run_time(-300, 1500, wait=True)
        robot.turn(-25)
        robot.stop()
        left_motor.run_time(velocidade, 750, wait=False)
        right_motor.run_time(velocidade, 750, wait= True)
        contador = 1
    else:
        left_motor.run(velocidade)
        right_motor.run(velocidade)

while sensor_cor.reflection() > 12:
    tempo.time()
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()


left_motor.run_time(-300, 3000, wait=False)
right_motor.run_time(-300, 3000, wait=True)

#-----C10-----
left_motor.run_time(0, 1850, wait=False)
right_motor.run_time(300, 1850, wait=True)

#-----R11-----
#reta frente banners
tempo.reset()
contador = 0

while contador < 1 and tempo.time() < 14500:
    if tempo.time() < 14500 and sensor_cor.reflection() < 12:
        left_motor.stop()
        right_motor.stop()
        #robot.turn(30)
        #robot.stop()
        left_motor.run_time(-300, 3500, wait=False)
        right_motor.run_time(-300, 3500, wait=True)
        robot.turn(-30)
        robot.stop()
        left_motor.run_time(velocidade, 750, wait=False)
        right_motor.run_time(velocidade, 750, wait= True)
        contador = 1
    else:
        left_motor.run(velocidade)
        right_motor.run(velocidade)

while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 2800, wait=False)
right_motor.run_time(-300, 2800, wait=True)

#-----C11-----
left_motor.run_time(0, 1550, wait=False)#1750 aqui
right_motor.run_time(300,1550, wait=True)

#-----R12-----
#PORTA DO LABOratório
while sensor_cor.reflection() > 12:
    tempo.time()
    left_motor.run(velocidade)
    right_motor.run(velocidade)


left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 3000, wait=False)
right_motor.run_time(-300, 3000, wait=True)

#-----C12-----
left_motor.run_time(300, 1450, wait=False)#1750
right_motor.run_time(0, 1450, wait=True)

#-----R13-----
#Extintor
while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 3000, wait=False)
right_motor.run_time(-300, 3000, wait=True)

#-----C13-----
left_motor.run_time(300, 1750, wait=False)
right_motor.run_time(0, 1750, wait=True)

#-----R14-----
#frente armario ->
tempo.reset()
contador = 0

while contador < 1 and tempo.time() < 7500:
    if tempo.time() < 7500 and sensor_cor.reflection() < 12:
        robot.turn(20)
        robot.stop()
        contador = 1
    else:
        left_motor.run(velocidade)
        right_motor.run(velocidade)

while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

ev3.screen.print(tempo.time(),end='\n')

left_motor.stop()
right_motor.stop()


left_motor.run_time(-300, 3000, wait=False)
right_motor.run_time(-300, 3000, wait=True)

#-----C14-----
left_motor.run_time(0, 1750, wait=False)
right_motor.run_time(300, 1750, wait=True)

#-----R15-----
#frente LMCA 
while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 3000, wait=False)
right_motor.run_time(-300, 3000, wait=True)

#-----C15-----

left_motor.run_time(0, 1750, wait=False)
right_motor.run_time(300, 1750, wait=True)

#-----R16-----
while sensor_cor.reflection() > 12:
    left_motor.run(velocidade)
    right_motor.run(velocidade)

left_motor.stop()
right_motor.stop()

left_motor.run_time(-300, 3000, wait=False)
right_motor.run_time(-300, 3000, wait=True)

#-----C16-----
#Ultima curva 
left_motor.run_time(300, 1750, wait=False)
right_motor.run_time(0, 1750, wait=True)

#-----R17-----
#reta final
contador = 0
while True:
    if sensor_cor.reflection() < 12 :
        robot.turn(10)
        robot.stop()
        contador = contador + 1
        if contador > 5:
            robot.turn(-40)
            robot.stop()
    else:
        left_motor.run(600)
        right_motor.run(600)
