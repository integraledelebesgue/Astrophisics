import numpy as np
import pickle
from barneshut import getForces
from math import sqrt
from scipy.constants import G
from scipy.integrate import solve_ivp


def getRadius(bodies:np.array) -> float:
    return sqrt( (max(abs(bodies[1, :]))**2) * (max(abs(bodies[2, :]))**2) )


class Model:

    def __init__(self, bodies:np.array, accuracy:float, time:float = 0, db:str = None) -> None:
        self.__bodies = bodies
        self.__radius = getRadius(bodies)
        self.__accuracy = accuracy
        self.__count = len(bodies)
        self.__time = time
        self.state = bodies[:, 1:3]
        self.db = db


    def __del__(self) -> None:
        print("Simulation over.")


    @property
    def bodies(self) -> np.array:
        return self.__bodies


    @property
    def count(self) -> int:
        return self.__count


    def refreshState(self):
        self.state = self.__bodies[:, 1:3]
        return


    def add(self, body:np.array) -> None:
        if (sh := body.shape) == (5, ):
            self.__bodies = np.concatenate((self.__bodies, [body]), axis=0)
            self.refreshState()

        else:
            raise Exception(f"Wrong body state array to be added; given shape is {sh}, expected (5, )")

        return


    def rhs(self, t:float , state:np.array) -> np.array:
        xs = np.array(state[::2])
        ys = np.array(state[1::2])
        masses = np.array([self.bodies[:, 0]]).T

        forces = np.array( getForces( np.concatenate( (masses, xs, ys), axis=1 ), self.__count, self.__radius, self.__accuracy ) ) * G

        for i in range(2*self.__count):
            forces[i][[0, 1]] /= masses[i//2]

        return forces


    def doStep(self, dt:float) -> np.array:
        sol = solve_ivp(self.rhs, [self.__time, self.__time + dt], self.bodies[:, 3:5].flatten(), t_eval = [self.__time + dt], vectorized = True)['y']

        return sol


