import numpy as np
import numpy.linalg

a=np.array([ [1, 1, 2, 3], 
            [1, 2, 3, 4], 
            [2, 3, 7, 5], 
            [3, 4, 5, 9]])

print(a)
print(numpy.linalg.det(a))