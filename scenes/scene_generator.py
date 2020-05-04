import random

lines = []

spheres_n = 20
lights_n = 10

lines.append("R\t1000\t1000") # Add resolution
lines.append("c\t0.0,0.0,20.0\t0.0,0.0,0.0\t90") # Add camera

def gen_pos():
    x = str(round(random.uniform(-20,20), 2))
    y = str(round(random.uniform(-20,20), 2))
    z = str(round(random.uniform(-20, -1), 2))
    return (x + "," + y + "," + z)

def gen_normvec():
    return (",".join([str(random.random() * 2 - 1) for i in range(3)]))

def gen_color():
    return (",".join([str(random.randrange(0,256)) for i in range(3)]))

def gen_sp():
    sp_line = ["sp"]
    sp_line.append(gen_pos())
    sp_line.append(str(round(random.uniform(0.5,5), 2)))
    sp_line.append(gen_color())
    return ("\t\t\t".join(sp_line))

def gen_light():
    l_line = ["l"]
    l_line.append(gen_pos())
    l_line.append(str(round(random.random(),2)))
    l_line.append(gen_color())
    return ("\t\t\t".join(l_line))

for i in range(spheres_n):
    lines.append(gen_sp())

for i in range(lights_n):
    lines.append(gen_light())

# Write result in random.rt
file = open("random.rt", "w")
file.write("\n".join(lines))
file.close()