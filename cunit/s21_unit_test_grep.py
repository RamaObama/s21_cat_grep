from os import system
import random
import os

orig_path = 'grep'
my_path = './../grep/s21_grep'

flags = [
    '-e',
    '-f',
    '-n',
    '-s',
    '-h',
    '-i',
    '-v',
    '-c',
    '-o',
    '-l'
]

files = [
    'file/a',
    'file/b',
    'file/c',
    'file/d',
    'file/e',
    'file/f',
    'file/g'
]

templates = [
    '\".\"',
    'Lorem',
    'tion',
    '123',
    '^$',
    '\"[[:lower:]]\"',
    '\"[[:blank:]]\"',
    '\"[[:alpha:]]\"',
    '\"\n\"',
    '\"[[:digit:]]\"'
]

def args():
    curr = random.choice(flags)
    line = ''
    for i in range(2):
        while (curr != '-e' and curr != '-f'):
            line += curr + ' '
            curr = random.choice(flags)
        if (curr == '-e'):
            line += '-e ' + random.choice(templates) + ' '
        else:
            line += '-f ' + random.choice(files) + ' '
        for i in range(1 + (int)(4 * random.random())):
            line += random.choice(files) + ' '
    # print(f'{line}')
    return line

count_fails = 0
for i in range(500):
    print(f'{i}\t{i - count_fails}\t{count_fails}\n')
    add = args()
    orig = orig_path + ' ' + add
    custom = my_path + ' ' + add
    print(add)
    # a, b, diff =  open('grep/0grepres', 'w'), open('grep/0s21_grepres', 'w'), open('grep/0diff', 'w')
    os.system(f'{orig_path} {add} > ../grep/0grepres')
    os.system(custom + ' > ../grep/0s21_grepres')
    os.system('diff ../grep/0grepres ../grep/0s21_grepres > ../grep/0diff')
    stat = os.stat('../grep/0diff')
    if (stat.st_size == 0):
        print('SUCCESS\n')
    else:
        print('FAIL\n')
        count_fails += 1
        # input()
    # a.close()
    # b.close()
    # diff.close()

