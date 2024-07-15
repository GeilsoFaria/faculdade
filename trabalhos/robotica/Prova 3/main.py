#!/usr/bin/env pybricks-micropython
from pybricks.hubs import EV3Brick
from pybricks.ev3devices import (Motor, TouchSensor, ColorSensor,
                                 InfraredSensor, UltrasonicSensor, GyroSensor)
from pybricks.parameters import Port, Stop, Direction, Button, Color
from pybricks.tools import wait, StopWatch, DataLog
from pybricks.robotics import DriveBase
from pybricks.media.ev3dev import SoundFile, ImageFile, Font
from pybricks.ev3devices import Motor, ColorSensor
from pybricks.parameters import Port
from pybricks.tools import wait
from pybricks.robotics import DriveBase

"""
    Prova 3: Chute ao gol com robô humanóide, modelo crawler. 
    !!! Cuidado que no eixo que faz o robô caminhar tem que sair da mesma posição, do contrário o robô caminha errado. !!!
    Alunos: Geilso Faria Rodrigues da Silva 
            Daniel Rocha Rodrigues
"""

#Inicializa os motores
left_motor = Motor(Port.A)
right_motor = Motor(Port.C)
#motor_chute = Motor(Port.D)

# Initialize the color senssor.
# sensor_distancia = InfraredSensor(Port.S2)

robot = DriveBase(left_motor, right_motor, wheel_diameter=42, axle_track=134)

while True:
    right_motor.run_target(155,80)
    robot.stop()
    left_motor.run_target(170,90)
    robot.stop()
    right_motor.run_target(155,-80)
    robot.stop()
    left_motor.run_target(170,-90)
    robot.stop()
    
    





    
    
   