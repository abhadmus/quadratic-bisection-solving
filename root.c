#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int x = 0;
	float a, b, c, d, range, root, u, l, m, funct_u, funct_l, funct_m, difference;
	char repeat = 'y';

    do {

    /*Initial text which introduces the user to the
    program and asks them to input their values*/

    difference = 1;

	printf("************************************************\n");
	printf("Welcome to the cubic root estimator.\n");
	printf("This estimates the value of one root of\n");
	printf("f(x) = ax^3 + bx^2 + cx + d.\n");
	printf("************************************************\n");

	printf("Enter the coefficients in the form 'a b c d': ");
	scanf("%f %f %f %f", &a, &b, &c, &d);

	/*Range to test the function across is defined.
	This is first done by equating range to the magnitude
	of the largest of the variables, then by multiplying this
	magnitude by 10, we can then use this as a base to check
	over a wide variety of values that's also proportional to
	the magnitude of the values given, similar to the example
	given in the brief of 0 to 10 being the range for values
	of 1, -1 and -6 for a, b and c.*/

    if (fabs(a) >= fabs (b)) {
        range = fabs (a);
    } else {
        range = fabs(b);
    }

    if (fabs(c) > range) {
        range = fabs (c);
    } else {
    }

    if (fabs(d) > range) {
        range = fabs (d);
    } else {
    }

    /*U and L, or upper and lower are then accordingly set to the positive and negative
    values of the range. The initial midpoint, as well as the initial function outputs at the
    said midpoint, u and l are also set, to set-up for the for loop*/

    range = range * 10;
    u = range;
    l = range * -1;
    m = (l + u) * 0.5;

    funct_l = a*(l*l*l) + b*(l*l) + c*(l) + d;
    funct_u = a*(u*u*u) + b*(u*u) + c*(u) + d;
    funct_m = a*(m*m*m) + b*(m*m) + c*(m) + d;

    /*The for-loop to carry out the repeated midpoint calculations and
    resulting interval reductions, until the eventual precision of 0.0001
    as a distance between the intervals is below.

    Within it you first have
    a triple case if statement: First case is the rare one, where 0 is found
    right away. For this case the loop is terminated and m is set as the root,
    to save time from unnecessary iterations. The second case is the effective
    statement that if u and m are the same, u is set to m, and the same for
    l. This done using the fact that u is always positive and l negative.

    The function values at these new points are calculated, for the adjusted l
    or u value, the next midpoint and the unadjusted u or l value.

    Finally another if statement is used to find the magnitude of the difference
    between the new interval points, which is used to determine whether to
    repeat the for loop or not in the next iteration*/

    for (; difference > 0.0001;) {

        if (funct_m == 0) {
            root = m;
            difference = 0;
        } else if (funct_m > 0) {
            u = m;
        } else {
            l = m;
        }

        m = (l + u) * 0.5;

        funct_l = a*(l*l*l) + b*(l*l) + c*(l) + d;
        funct_u = a*(u*u*u) + b*(u*u) + c*(u) + d;
        funct_m = a*(m*m*m) + b*(m*m) + c*(m) + d;

        if (difference == 0) {
        } else {
            if (fabs(funct_l) < fabs(funct_u)) {
                difference = fabs(funct_u) - fabs(funct_l);
            } else {
                difference = fabs(funct_l) - fabs(funct_u);
            }
        }

    }

    /*The root value found at this final m value is set as the root*/

    root = m;

	/*Final result for the root value is printed*/

	printf("There is a root at: x = %.4f\n", root);

	/*User is queried on whether they wish to
	use the function another time. This is done by
	scanning for a character, of either y or n, and
	depending on which character is received an if
	statement is used to either restart or terminate
	the program, using a do-while loop which was
	established in the beginning of the program*/

	printf("Do you wish to try another quadratic [y/n]: ");
	scanf(" %c", &repeat);

    } while (repeat == 'y');

	return 0;

}
