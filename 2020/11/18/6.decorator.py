def add_two_number(num_1: int, num_2: int) -> int:
    print(num_1 + num_2)
    return num_1 + num_2

def show() -> None:
    def print_func_name() -> None:
        print("this is a function")
   
    print_func_name() 
    print("Hello world")

def call_func(func, *args, **kwargs) -> None:
    func(*args, **kwargs)

call_func(show)
call_func(add_two_number, 1, 3)