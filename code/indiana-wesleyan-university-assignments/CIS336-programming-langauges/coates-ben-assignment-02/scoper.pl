# Benjamin Coates
# CIS 336: Programming Languages
# FA 2014
# Dr. Joe Hoffert
# Programming Exercises p. 233, Ex. 1
# _________________________________________


# Function handles and shows the effect of static scoping
# Static scoping in Perl depend on scoping of the functions.
# - Global scopes can be seen anywhere in the program
# - Local scopes can be seen in the function they are declared and by other 
#   functions called within the local scope.
# - My scope (private scope) can only be seen within the function itself and 
#   cannot be seen by other functions called within the scope.
# **For the function below the $var variable is treated as global in the scope of 
# **the "static" function even though be techinical defintion it is not global.
sub static {

    # Function that outputs the value of $var
    sub printValue {
        print "var has the value $var \n";
    }

    # Function that declares the local scope variable $var and calls printValue to output it 
    sub staticLocal {
        local $var = "local";
        printValue();
    }

    # Function that delcares a static varibale $var and calls printValue to output it.
    # Also outputs a print statement that oringates in the function itself
    # The output from "printValue" function might be expected to be "private" 
    # But the nature of the "my" variable in Pearl makes the variable only visible to the function itself.
    # The second statement that originates in the function itself outputs "private" as the variable value.
    sub staticPrivate {
        my $var = "private";
        printValue();
        print "var has the valu $var \n";
    }
    
    # delcaration of the variable that is relatively global in scope relative to the static functions.
    $var = "global";
    
    printValue();   # Results in "var has the value global" being outputted
    staticLocal();  # Results in "var has the value local" being outputted
    staticPrivate();# Results in "var has the value global" and
                    # "var has the value private" being outputted
    printValue();   # Results in "var has the value global" being outputted
}

# Function handles and shows the effect of dynamic scoping
# Dynamic scoping in Perl depend in the order in which they are declared.
# Scoping is of no consequence
sub dynamic {
    
    # This function sets the variable x equal to the integer 7 and prints it.
    sub sub1 {
        $x = 7;
        print "x has the value $x \n";
    }
    
    # This function sets the variable y = the variable x and z = 3.
    # Becuase of dynamic scoping the variable will be assigned the value of the variable x
    # most recently given the variable.
    sub sub2
    {
        $y = $x;
        $z = 3;
        print "y has the value $y \n";
        print "z has the value $z \n";
    }
    
    # declares the varibale x = to 3.
    $x = 3;
    
    print "x has the value $x \n";  # Outputs "x has the value 3
    sub1();                         # Outputs "x has the value 7
    sub2();                         # Outputs "y has the value 7" (inherited from the previous function)
                                    # and "z has the value 3"
    print "x has the value $x \n";  # Outputs "x has the value 7"
                                    # (regardless of scoping the most recent declaration of x was 7)
}

static();
dynamic();