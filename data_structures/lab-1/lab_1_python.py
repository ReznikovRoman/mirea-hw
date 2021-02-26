from typing import List
import random


def print_array():
    print(*arr)


def populate_array(arr_length: int = 10) -> List[int]:
    return random.sample(range(1, 2), arr_length)
    

def del_first_method(arr: List[int], key: int):
    i, conditions_count, permutations_count = 0, 0, 0
    
    
    while i < len(arr):
        conditions_count += 1
        
        if arr[i] == key:
            arr.pop(i)
            permutations_count += 1
        else:
            i += 1
        
        conditions_count += 1
        
    print("New array: ")
    print_array(arr)
    print(f"Conditions count: {conditions_count}; Permutations count: {permutations_count}")


def main():
    n = 10
    key = 1
    arr = populate_array()
    
    print("Initial array: ")
    print_array(arr)
    


if __name__ == 'main':
    main()