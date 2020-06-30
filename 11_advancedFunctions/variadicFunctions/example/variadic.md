# variadic means unknown number of arguments

standard library stdarg.h provides you with routines to write some of your own variadic functions

has 2 parts mandatory arguments and optional arguments
* mandatory at least one is required

common practice is that the first argument signals how many arguments there are


when creating a variadic function, you must understand how to reference
the variable number of arguments used inside the function
* you do not know how many there are and you cannot possibly give them names
* you can solve this problem indirectly, through pointers

the stdarg.h library header provides you with routines that are implemented as macros (look and operate like functions)
* you need to use these when implementing your own variadic function

`va_list`
* used in situations in which we need to access optional parameters and it is an argument list
* represents a data object used to hold the parameters corresponding to the ellipsis part
of the parameter list

`va_start`
* will connect our argument list with some argument pointer
* the list specified in `va_list` is the first argument and the second argument is 
the last fixed parameter

`va_arg`
* will fetch the current argument connected to the argument list
* we would need to know the type of the argument that we are reading

`va_end`
* used in situations when we would like to stop using the variable argument list (cleanup)

`va_copy`
* save current location

# creating a variadic function 
## (STEP 1)

to create a function with a variable number of arguments, perform the following steps

provide a function prototype using an ellipsis
* the ellipsis indicates that a variable number of arguments may follow
any number of fixed arguments
* must have at least one fixed argument

```c
void f1(int n, ...); // valid
int f2(const char * s, int k, ...); // valid
char f3(char c1, ..., char c2); // invalid, ellipsis not last
double f4(...); // invalid, no parameter
```

## (STEP 2 + 3)
* create a `va_list` type variable in the function definition
* initialize the variable to an argument list
  * need to copy the argument list ot the `va_list` variable using `va_start`

```c
double average(double v1, double v2, ...) {
  va_list parg;
  ...
  va_start( parg, v2);
  ...
}
```

* first declare the variable parg of type `va_list`

* call `va_start()` with this as the first argument and specify the last fixed parameter v2 as the second argument
  * effect of the call to `va_start()` is to set the variable parg to point to the first variable argument that is passed to the function when it is called
    * still do not know what type of value this represents

## (STEP 4)

* access the contents of the argument list using `va_arg()`
  * takes two arguments: a type `va_list` variable and a type name
  * the first time it is called, it returns the first item in the list
  * the next time it is called, it returns the next item, and so on
  * the type argument specifies the type of value returned
    * has to match the specification

```c
double someFunction(int lim, ...) {
  va_list ap; //declare object to hold arguments
  va_start(ap, lim); //initialize ap to argument list

  double tic = va_arg(ap, double); //retrieve first argument
  int toc = va_arg(ap, int);  //retrieve second argument
  // type conversion doesn't work here
}
```
## (STEP 5)

* clean up by using the `va_end()` macro as your last step
  * essential to tidy up loose ends left the process
  * takes a `va_list` variable as its argument
    * reset the ap pointer to NULL
  * if you omit this call, your program may not work properly
    * variable may not be usable unless you use `va_start` to reinitialize it

```c
  va_end(ap) // clean up
```

# `va_copy`

`va_arg()` does not provide a way to back up to previous arguments

* it is possible that you may need to process a variable argument list more than once
  * may be useful to preserve a copy of the `va_list` type variable
  * use `va_copy()` 2 arguments are both type `va_list` variables, copies the second argument
to the first

```c
va_list parg; 
va_list parg_copy; // creates a new va_list variable, parg_copy
va_copy(parg_copy, parg); // copies the contents of parg to parg_copy
...
// you can process parg and parg_copy independently to extract argument values using va_arg()
// and va_end()
```

`va_copy` routine copies the `va_list` object in whatever state it is in
* if you have executed `va_arg` with parg to extract argument values from the list prior
to using the `va_copy()` routine, `parg_copy` will be in an identical state to parg with some argument values already extracted

* do not use the `va_list` object `parg_copy` as the destination for another copy operation before you have executed `va_end()` for `parg_copy`
