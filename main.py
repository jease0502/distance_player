from parameter import Parameters as parm

import serial
import pyglet

s = serial.Serial('COM10', 9600)
source = pyglet.media.load("video/video.mp4")
format = source.video_format

player = pyglet.media.Player()

window = pyglet.window.Window(width=format.width, height=format.height)


@window.event
def on_draw():
    if player.source and player.source.video_format:
        player.get_texture().blit(0, 0)


while True:
    get_data = int(s.readline())
    if get_data < parm.distance:
        print(get_data)
        print("你拿走了一個雞蛋")
        player.queue(source)
        player.play()
        pyglet.app.run()
