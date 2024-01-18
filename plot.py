import sys
import os

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import csv

plt.style.use('seaborn-v0_8-whitegrid')

def plot_multiline(file: str):
    data = pd.read_csv(file, sep=',', header=None)
    plt.figure(figsize=(12, 6))

    plt.plot(data[0], data[1], label='Tabu Search with Insert neighbourhood', marker='.', markersize=7)
    plt.plot(data[2], data[3], label='Simulated Annealing with a = 0.8', marker='.', markersize=7)
    plt.plot(data[4], data[5], label='Genetic Algorithm, population = 5000, OX with rate 0.10, displacement Crossover with rate 0.8', marker='.', markersize=7)
    # plt.plot(data[6], data[7], label='Mutation rate 0.01, OX, Displacement Crossover', marker='.', markersize=7)
    # plt.plot(data[8], data[9], label='Mutation rate 0.05, OX, Displacement Crossover', marker='.', markersize=7)
    # plt.plot(data[10], data[11], label='Mutation rate 0.10, OX, Displacement Crossover', marker='.', markersize=7)
    # plt.plot(data[12], data[13], label='Mutation rate 0.01, PMX, Scramble Crossover', marker='.', markersize=7)
    # plt.plot(data[14], data[15], label='Mutation rate 0.05, PMX, Scramble Crossover', marker='.', markersize=7)
    # plt.plot(data[16], data[17], label='Mutation rate 0.10, PMX, Scramble Crossover', marker='.', markersize=7)
    # plt.plot(data[18], data[19], label='Mutation rate 0.01, OX, Scramble Crossover', marker='.', markersize=7)
    # plt.plot(data[20], data[21], label='Mutation rate 0.05, OX, Scramble Crossover', marker='.', markersize=7)
    # plt.plot(data[22], data[23], label='Mutation rate 0.10, OX, Scramble Crossover', marker='.', markersize=7)

    plt.title('Comparison metaheuristic algorithms for ftv170.xml')
    plt.legend()
    plt.ylabel('Relative error [%]')
    plt.xlabel('Time [s]')

    plt.yticks(np.arange(0, 760, step=30))

    # plt.yscale('log')
    fig = plt.gcf()
    plt.show()

    if not os.path.exists('img'):
        os.mkdir('img')

    fig.savefig(f'img/{file.removesuffix(".csv")}.png', bbox_inches='tight')


plot_multiline("comparison_170.csv")
