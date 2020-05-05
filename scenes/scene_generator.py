from random import *
from vectormath import *
from math import *

# Resolution
xres = 600
yres = 600

# Numbers of cameras, lights and objects
ncams = 10
nlights = 10
nspheres = 25

# Generators utilities

def gen_pos(bias=0):
    x = str(round(uniform(-20-bias, 20+bias), 2))
    y = str(round(uniform(-20-bias, 20+bias), 2))
    z = str(round(uniform(-20-bias, 20+bias), 2))
    return (x + "," + y + "," + z)

def gen_normvec():
    return (",".join([str(random() * 2 - 1) for i in range(3)]))

def gen_color():
    return (",".join([str(randrange(0,256)) for i in range(3)]))

def gen_sp():
    sp_line = ["sp"]
    sp_line.append(gen_pos())
    sp_line.append(str(round(uniform(0.5,5), 2)))
    sp_line.append(gen_color())
    return ("\t\t\t".join(sp_line))

def gen_light():
    l_line = ["l"]
    l_line.append(gen_pos(20))
    l_line.append(str(round(random(),2)))
    l_line.append(gen_color())
    return ("\t\t\t".join(l_line))

def gen_cam():
	c_line = ["c"]
	from_center = Vector3(round(random() * 2 - 1, 2),round(random() * 2 - 1, 2),round(random() * 2 - 1, 2))
	to_center = from_center * -1
	from_center.normalize()
	from_center *= 40
	c_line.append(str(round(from_center.x, 2)) + "," + str(round(from_center.y, 2)) + "," + str(round(from_center.z, 2)))
	c_line.append(str(to_center.x) + "," + str(to_center.y) + "," + str(to_center.z))
	c_line.append("90")
	return ("\t\t\t".join(c_line))


# Script
lines = []
# Add resolution
lines.append("R\t" + str(xres) + "\t" + str(yres))
# Add cameras
lines.append("c\t\t\t0.0,0.0,40.0\t\t\t0.0,0.0,0.0\t\t\t90")
if ncams > 1:
	for i in range(ncams - 1):
		lines.append(gen_cam())
# Append spheres
for i in range(nspheres):
    lines.append(gen_sp())
# Append lights
for i in range(nlights):
    lines.append(gen_light())

# Write the result in random.rt
file = open("random.rt", "w")
file.write("\n".join(lines))
file.close()