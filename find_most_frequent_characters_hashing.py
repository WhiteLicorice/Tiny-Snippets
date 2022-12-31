##  This is a small subprogram written by Rene Andre B. Jocsing in Python
##  Input: String
##  Process: Find the maximum occurring characters in a string, not including whitespace
##  Output: Array of maximum appearing characters in a string and their frequency
##  Return: Tuple -> ([most_frequent_characters], max_frequency)

def find_mode(string : str = "this is a test string") -> tuple:
    character_counts = dict()               ##  Initialize a dictionary for storing character, frequency key-value pairs
    temp_string = ''.join(string.split())   ##  Store a copy of the string argument into temp_string, remove all whitespace

    if(len(temp_string) == 0):
        raise Exception ("Please pass a non-empty string.")     ##  Throw error if input string is empty (all whitespace)
    
    ##  Count the frequency of each character in the stripped string via hashing algorithm -> O(N) time, O(N) space
    for character in temp_string:
        if character in character_counts:
            character_counts[character] += 1
        else:
            character_counts[character] = 1
            
    ##  Lambda to find the maximum frequency in the hashmap
    max_frequency = (max(character_counts.items(), key = lambda char_freq: char_freq[1]))[1]
    
    most_frequent_characters = list()   ##  Initialize a list for storing the most frequent characters

    ##  Find the characters with frequencies that match the maximum frequency
    for character, count in character_counts.items():
        if count == max_frequency:
            most_frequent_characters.append(character)
            
    ##  Return a tuple in the form of ([most_frequent_characters], max_frequency)
    return (most_frequent_characters, max_frequency)

##  Driver function to test program -> calls core function and prints out the input and the output
def main(string : str = "this is a test string") -> None:
    res = find_mode(string)
    print("String:", string)
    print("Modal Character(s):", *res[0])
    print("Frequency:", res[1])
