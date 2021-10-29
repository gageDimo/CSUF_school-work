# Gage Dimapindan, CWID: 888017746
# CPSC 481, Fall 2021
# Project 2

from games import *

# ----------------------- code goes here -----------------------

class GameOfNim(Game):  # goal of game is to avoid taking the last object of board

    # default constructor; initializes board
    def __init__(self, board):

        possible_moves = [(r, n) for r in range(0, len(board)) for n in range(1, board[r]+1)]

        # to_move: C = comp, P = plyr
        self.initial = GameState(to_move='C', utility=0, board=board, moves=possible_moves)

    # returns new state reached from given state and given move
    def result(self, state, move):

        # check for illegal move to cancel effect
        if move not in state.moves:
            return state

        newBoard = state.board.copy()

        newBoard[move[0]] = newBoard[move[0]] - move[1]

        newMoves = [(r, n) for r in range(0, len(newBoard)) for n in range(1, newBoard[r]+1)]

        newPlyr = 'P' if state.to_move == 'C' else 'C'

        return GameState(to_move=newPlyr,
                         utility=self.compute_utility(newBoard, newPlyr),
                         board=newBoard, moves=newMoves)

    # returns a list of valid actions in the given state
    def actions(self, state):
        # game rule: if current row being removed is not zero, players are stuck to that row

        return state.moves

    # returns True if given state represents end of game
    def terminal_test(self, state):

        # check if board is empty
        for idx in state.board:
            if idx != 0:
                return False

        return True

    # returns +1 if MAX wins or -1 if MIN wins
    def utility(self, state, player):

        if player == 'C':
            return state.utility
        else:
            return -state.utility

    # helper function for 'utility'; determines whose turn it currently is
    def compute_utility(self, board, player):

        if sum(board) == 0:
            if player == 'C':
                return 1
            else:
                return -1

        return 0

# --------------------------------------------------------------

if __name__ == "__main__":
    nim = GameOfNim(board=[0,5,3,1])
#    print(nim.initial.board)
#    print(nim.initial.moves)
    utility = nim.play_game(alpha_beta_player, query_player) # computer moves first
#    print(nim.result(nim.initial, (1,2)))  # results test; should return [7,3,3,1]
#    print(nim.actions([1,3]))  # actions test; should return [(0,1), (1,1), (1,2), (1,3)]
#    print(nim.terminal_test([0,0,0,0,0,0])) # terminal testing; should return True
#    print(nim.utility([0,0,0], 'C'))  # utility testing; should return -1
#    print(nim.compute_utility([0,0,0,1,0], 'P'))  # compute utility testing; should return 0

    if (utility < 0):
        print("MIN won the game")
    else:
        print("MAX won the game")