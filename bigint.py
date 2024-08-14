# Python 3.10 decided big integers are a denial of service attack vector
import sys
sys.set_int_max_str_digits(0)

def op_add(x, y):
    return x + y

def op_sub(x, y):
    return x - y

def op_mul(x, y):
    return x * y

def op_div(x, y):
    # Python rounds towards -inf instead of towards zero
    # Not immediately convinced by that so round towards zero instead
    if (x < 0) != (y < 0):
        return op_neg(op_div(op_abs(x), op_abs(y)))
    
    return x // y

def op_rem(x, y):
    return x % y

def op_ash(x, y):
    return x >> y

def op_lsh(x, y):
    return x << y

def op_rsh(x, y):
    # todo, work out how to represent this in python
    return 0


def op_not(x):
    # This may have printing challenges
    return ~x

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

def op_cmp(x, y):
    if x < y:
        return -1
    if y < x:
        return +1
    return 0

def op_equal(x, y):
    return x == y


opmap = {
    'add' : op_add,
    'sub' : op_sub,
    'mul' : op_mul,
    'div' : op_div,
    'rem' : op_rem,
    
    'lsh' : op_lsh,
    'shift_left' : op_lsh,
    'rsh' : op_rsh,
    'shift_right' : op_rsh,
    
    'ash' : op_ash,
    'bitwise_not' : op_not,
    'bitwise_or' : op_or,
    'bitwise_and' : op_and,
    'bitwise_xor' : op_xor,
    'incr' : op_incr,
    'decr' : op_decr,
    'absolute' : op_abs,
    'negate' : op_neg,
    'cmp' : op_cmp,
    'equal' : op_equal,
}
