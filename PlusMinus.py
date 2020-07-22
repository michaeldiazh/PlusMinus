#!/usr/bin/python
import math
import os
import random
import re
import sys

def plusMinus(arr):
    pos,neg,zero = (0,0,0)
    for i in arr:
        pos += 1 if i>0 else 0 
        neg += 1 if i<0 else 0 
        zero += 1 if i == 0 else 0
    pos, neg, zero = (float(pos)/len(arr),float(neg)/len(arr),float(zero)/len(arr))
    return {round(pos,6), round(neg,6), round(zero,6)}

def main():
    input_file = open("input01.txt",'r')
    if input_file.mode == 'r':
        data = input_file.read().replace("\n"," ")
        (size,arr) = (data.split(" ")[0],data.split(" ")[1:])
        arr = list(map(int,arr))
    for i in plusMinus(arr):
        print("%.6f"%i)
        

main()