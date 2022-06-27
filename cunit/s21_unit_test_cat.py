from os import system
import random
import os

orig_path = 'cat'
my_path = './../cat/s21_cat'

flags = [
    '-e',
    '-b',
    '-n',
    '-s',
    '-t',
    '-v'
]

files = [
    'file/a',
    'file/b',
    'file/c',
    'file/d',
    'file/e',
    'file/f',
    'file/g',
    'file/weirdo.txt'
]

def args():
    curr = random.choice(flags)
    line = ''
    for i in range(random.randrange(1, 3)):
        line += random.choice(flags) + ' '
    for i in range(random.randrange(1, 3)):
        line += random.choice(files) + ' '
    return line

count_fails = 0
for i in range(500):
    print(f'{i}\t{i - count_fails}\t{count_fails}\n')
    add = args()
    print(add)
    os.system(f'{orig_path} {add} > ../cat/0catres')
    os.system(f'{my_path} {add} > ../cat/0s21_catres')
    os.system('diff ../cat/0catres ../cat/0s21_catres > ../cat/0diff')
    stat = os.stat('../cat/0diff')
    if (stat.st_size == 0):
        print('SUCCESS\n')
    else:
        print('FAIL\n')
        count_fails += 1
        input()