import math


def convert_coordinates(coord_from, coord_to, a, b, c):
    if coord_from == 1 and coord_to == 2:  # 직교 -> 원통
        x, y, z = a, b, c
        r = math.sqrt(x ** 2 + y ** 2)
        phi = math.atan2(y, x)
        if phi < 0:
            phi += 2 * math.pi
        return r, phi, z
    elif coord_from == 1 and coord_to == 3:  # 직교 -> 구면
        x, y, z = a, b, c
        rho = math.sqrt(x ** 2 + y ** 2 + z ** 2)
        theta = math.acos(z / rho) if rho != 0 else 0
        phi = math.atan2(y, x)
        if phi < 0:
            phi += 2 * math.pi
        return rho, theta, phi
    elif coord_from == 2 and coord_to == 1:  # 원통 -> 직교
        r, phi, z = a, b, c
        x = r * math.cos(phi)
        y = r * math.sin(phi)
        return x, y, z
    elif coord_from == 2 and coord_to == 3:  # 원통 -> 구면
        r, phi, z = a, b, c
        rho = math.sqrt(r ** 2 + z ** 2)
        theta = math.atan2(r, z)
        return rho, theta, phi
    elif coord_from == 3 and coord_to == 1:  # 구면 -> 직교
        rho, theta, phi = a, b, c
        x = rho * math.sin(theta) * math.cos(phi)
        y = rho * math.sin(theta) * math.sin(phi)
        z = rho * math.cos(theta)
        return x, y, z
    elif coord_from == 3 and coord_to == 2:  # 구면 -> 원통
        rho, theta, phi = a, b, c
        r = rho * math.sin(theta)
        z = rho * math.cos(theta)
        return r, phi, z


T = int(input())
for _ in range(T):
    coord_from, coord_to = map(int, input().split())
    a, b, c = map(float, input().split())

    result = convert_coordinates(coord_from, coord_to, a, b, c)

    print(f"{result[0]:.8f} {result[1]:.8f} {result[2]:.8f}")
