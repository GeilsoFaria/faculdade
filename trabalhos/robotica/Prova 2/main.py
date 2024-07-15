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
    Prova 2: Completar circuito apenas seguindo linha preta
    !!! Se quiser um valor seguro use 160 em DRIVE_SPEED ou menor !!!
    Alunos: Geilso Faria Rodrigues da Silva 
            Daniel Rocha Rodrigues
"""

#Inicializa os motores
left_motor = Motor(Port.A)
right_motor = Motor(Port.C)
tempo = StopWatch()
sensor_luz = ColorSensor(Port.S3)

luz = sensor_luz.reflection()

ev3 = EV3Brick()
robot = DriveBase(left_motor, right_motor, wheel_diameter=42, axle_track=134)

#Tempo=2:18 - Speed=170 Ganho= 5.5-Pequenas saídas - Black= 3 White=30
#Tempo=2:10 - Speed=180 Ganho= 5.5-Pequenas saídas - Black= 3 White=30
#Tempo=2:07 - Speed=185 Ganho= 5.5-Pequenas saídas- Black= 3 White=30
BLACK = 3
WHITE = 30
threshold = (BLACK + WHITE) / 2

DRIVE_SPEED = 185 #160 seguro


PROPORTIONAL_GAIN = 5.5


tempo.reset()

while True:
     # Calculate the deviation from the threshold.
    luz = sensor_luz.reflection()
    deviation = sensor_luz.reflection() - threshold
    # Calculate the turn rate.
    turn_rate = PROPORTIONAL_GAIN * deviation

    # Set the drive base speed and turn rate.
    robot.drive(DRIVE_SPEED, turn_rate)
    wait(10)
