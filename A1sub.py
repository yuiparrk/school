import csv
import random

from typing import List, Dict, Tuple, Any, Optional
Board = List[List[Optional[Tuple[str, int]]]]

### BEGIN SOLUTION PROBLEM 1

def getNeighbors(board: Board, x: int, y:int) -> List[Optional[Tuple[int, int]]]:
    pass

### BEGIN SOLUTION PROBLEM 2

def generateBoard(lands: Dict[str,int], numbers: Dict[str,int], seed: int = None, floating_desert: bool = False) -> Board:
    pass

### BEGIN SOLUTION PROBLEM 3

def check_no_2_next_to_12(board:  Board)-> bool:
    pass

### BEGIN SOLUTION PROBLEM 4

def generateValidBoard(lands: Dict[str,int], numbers: Dict[str,int], seed: int = None, floating_desert: bool = False, max_tries: int = 100) -> Board:
    pass

### BEGIN SOLUTION PROBLEM 5

def createValidBoardsDatasets(num_boards: int, outFile: str, seed: int = None, floating_desert: bool = False) -> None:
    pass

### BEGIN SOLUTION PROBLEM 6

def getTopSongsInfo(filename: str) -> Dict[str, List[str]]:
    pass

### BEGIN SOLUTION PROBLEM 7
    songs = {}
    
    with open(filename, "r") as file:
        content = csv.DictReader(file)
        
        for row in content:
            song_name = row['name']
            artists = row['artists']
            
            if song_name not in songs:
                artist_list = artists.split(',')
                new_artists = []
                
                for artist in artist_list:
                    new_artists.append(artist.strip())
                
                songs[song_name] = new_artists
                
    return songs


def getTopArtistsInfo(song_dict: Dict[str, List[str]]) -> Dict[str, List[str]]:
    pass


### BEGIN SOLUTION PROBLEM 8

def TopSongsPerSeason(filename: str) -> Dict[str, List[Tuple[str, str, float]]]:
    pass
            
        
    
    

