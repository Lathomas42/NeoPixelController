import serial
import time
import numpy
import json

class Neopixel(object):
    def __init__(self, port, n_pixels):
        self.con = serial.Serial(port, 115200)
        self.n_pixels = n_pixels
        self.pixels = numpy.zeros((n_pixels, 3))
        self.configs = {}
        try:
            f = open('.configs.json','r')
            self.configs = json.load(f)
        except:
            f = 1

    def set_led(self, index, r, g, b):
        self.con.write('0, {}, {}, {}, {};'.format(index, r, g,b))
        self.pixels[index] = [r,g,b]
        time.sleep(.05)

    def dim_ring(self, brightness):
        if (brightness < 1 & brightness > 0):
            brightness = int(brightness*255)
        self.con.write('1, {};'.format(brightness))

    def set_every_n(self, n, r, g, b, offset=0):
        for i in range(0, int(self.n_pixels/n)):
            ind = (i*n + offset )% self.n_pixels
            self.set_led(ind, r, g, b)

    def save_config(self, name):
        self.configs[name] = self.pixels.copy().tolist()
        with open('.configs.json','w') as outfile:
            json.dump(self.configs, outfile)

    def load_config(self, name):
        pix = self.configs[name]
        for i in range(0,self.n_pixels):
            row = pix[i]
            self.set_led(i, row[0], row[1], row[2])
