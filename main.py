import subprocess
import os

exe_path = "./cmake-build-release/genetic-algorithm.exe"
directory_path = "population"


def run_exe_and_save_output():
    for f in files:
        for parameter in data:
            file_name = str(f[0]).split("/")[1];
            csv_file_path = f'{directory_path}/{file_name}_{parameter[0]}_{parameter[1]}_{parameter[2]}.csv'
            command = [exe_path, f[0], f[1], parameter[0], parameter[1], parameter[2], parameter[3], parameter[4], f[2]]
            for i in range(0, 3):
                result = subprocess.run(command, capture_output=True, text=True)
                print(result)
                output = result.stdout.strip()
                row = f"{i},{output}\n"
                with open(csv_file_path, 'a+', newline='') as file:
                    file.write(row)


data = [
    ("100", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("1000", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("5000", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("100", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("1000", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("5000", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("100", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("1000", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("5000", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("100", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("1000", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("5000", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("100", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("1000", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("5000", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("100", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("1000", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("5000", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("100", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("1000", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("5000", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION", "0.8", "crossover"),
    ("100", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("1000", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
    ("5000", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION", "0.8", "crossover"),
]

files = [
    ("data/ftv47.xml", "120", "ftv47", "100"),
    ("data/ftv170.xml", "240", "ftv170", "5000"),
    ("data/rbg403.xml", "360", "rbg403", "5000"),
]

if not os.path.exists(directory_path):
    os.makedirs(directory_path)

if not os.path.exists('results'):
    os.makedirs('results')

run_exe_and_save_output()


# ("100", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("1000", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("5000", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("100", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("1000", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("5000", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("100", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("1000", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("5000", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("100", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("1000", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("5000", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("100", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("1000", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("5000", "PARTIALLY_MAPPED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("100", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("1000", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("5000", "PARTIALLY_MAPPED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("100", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("1000", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("5000", "ORDERED_CROSSOVER", "DISPLACEMENT_MUTATION"),
# ("100", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("1000", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION"),
# ("5000", "ORDERED_CROSSOVER", "SCRAMBLE_MUTATION"),