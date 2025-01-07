import os

from pathlib import Path

from numpy import genfromtxt
import matplotlib.pyplot as plt

os.chdir(Path(__file__).parent)

aos = genfromtxt('aos.gcc.dat', delimiter=' ')
soa = genfromtxt('soa.gcc.dat', delimiter=' ')

"""
    memory footprint in kB
    Mflop/s of distance(...)
    Mflop/s of distcheck(...)
    Mflop/s of total program
    runtime in secs
"""

title = ["", "Mflop/s of distance", "Mflop/s of distcheck", "Mflop/s of total program", "runtime in secs"]

for i in range(1, 5):
    plt.figure()
    plt.plot(aos[:, 0], aos[:, i], label="AOS")
    plt.plot(soa[:, 0], soa[:, i], label="SOA")
    if i < 4:
        plt.axvline(x=416, color='b', label='L1d')
        plt.axvline(x=9.5 * 1024, color='b', label='L2')
        plt.axvline(x=24 * 1024, color='b', label='L3')
    plt.xscale('log')
    plt.legend()
    plt.title(title[i])

plt.show()
