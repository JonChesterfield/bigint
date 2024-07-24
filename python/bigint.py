
def op_add(x, y):
    return x + y

def op_sub(x, y):
    return x - y

def op_mul(x, y):
    return x * y

def op_div(x, y):
    return x // y

def op_rem(x, y):
    return x % y

def op_and(x, y):
    return x & y

def op_or(x, y):
    return x | y

def op_xor(x, y):
    return x ^ y


def op_incr(x):
    return x + 1

def op_decr(x):
    return x - 1

def op_abs(x):
    if x >= 0:
        return x
    else:
        return -1 * x
        

def op_neg(x):
    return -1 * x
