#include <iostream>
#include <vector>

using namespace std;

vector<int> computeDerivative(vector<int> const& coefs)
{
	vector<int> derivative;
	for (unsigned int i = 1; i < coefs.size(); i++)
	{
		derivative.push_back(i * coefs[i]);
	}
	return derivative;
}

void displayExpression(vector<int> const& exspression)
{
	exspression[1] > 0 ? 
		cout << exspression[0] << " + " : 
		cout << exspression[0];
	for (unsigned int i = 1; i < exspression.size()-1; i++)
	{
		exspression[i+1] > 0 ? 
			cout << exspression[i] << "x^" << i << "+" : 
			cout << exspression[i] << "x^" << i;
	}
	cout << exspression[exspression.size() - 1] << "x^" << exspression.size() - 1 << endl << endl;
}

vector<int> setCoefs(int amount)
{
	vector<int> coefs;
	int temp = 0;
	for (int i = 0; i < amount; i++)
	{
		cin >> temp;
		coefs.push_back(temp);
	}
	return coefs;
}

pair<double, double> findRoots(vector<int> quadEquation)
{
	int a = quadEquation[2];
	int b = quadEquation[1];
	int c = quadEquation[0];
	int d = b * b - 4 * a * c;

	double sqrt_val = sqrt(abs(d));

	if (d > 0) 
	{
		double x1 = (double)(-b - sqrt_val) / (2 * a);
		double x2 = (double)(-b + sqrt_val) / (2 * a);
		return make_pair(x1, x2);
	}
	else if (d == 0) 
	{
		double x = -(double)b / (2 * a);
		return make_pair(x, x);
	}
	else // d < 0
	{
		cout << "Roots are complex \n";
		cout << -(double)b / (2 * a) << " + i"
			<< sqrt_val / (2 * a) << "\n"
			<< -(double)b / (2 * a) << " - i"
			<< sqrt_val / (2 * a);
		return make_pair(-(double)b / (2 * a), (double)b / (2 * a));
	}
}

void displayRoots(pair<double, double> roots) 
{
	cout << "Roots of the quad equation : \n" << 
		"x1 = " << roots.first << 
		", x2 = " << roots.second << endl << endl;
}

pair<double, double> computeExtremas(pair<double, double> roots, vector<int> const& secondDerivative)
{
	return make_pair(secondDerivative.front() + secondDerivative.back() * roots.first, 
		secondDerivative.front() + secondDerivative.back() * roots.second);
}

void displayExtremas(pair<double, double> extremas, pair<double, double> roots, vector<int> const& secondDerivative)
{
	cout << "Type of extremas :\n" << "f\"(" << roots.first << ") = " << secondDerivative.front()
		<< " + " << secondDerivative.back() << " * " << roots.first
		<< " = " << extremas.first << " < 0 - max" << endl;

	cout << "- f\"(" << roots.second << ") = " << secondDerivative.front()
		<< " + " << secondDerivative.back() << " * " << roots.second
		<< " = " << extremas.second << " > 0 - min" << endl << endl;
}

pair<double, double> computeFunction(pair<double, double> & roots, vector<int>& coefs)
{
	double first = 0.0, second = 0.0;
	for (unsigned int i = 0; i < coefs.size(); i++)
	{
		first += coefs[i] * pow(roots.first, i);
	}

	for (unsigned int i = 0; i < coefs.size(); i++)
	{
		second += coefs[i] * pow(roots.second, i);
	}
	return make_pair(first, second);
}

void displayFunctionValues(pair<double, double> const& roots, vector<int> const& expression, pair<double, double> const& values)
{
	cout << "The function values at the (" << roots.first << " : " << roots.second <<
		") extremum points : \n" << "f(" << roots.first << ") = ";
	expression[1] > 0 ?
		cout << expression[0] << " + " :
		cout << expression[0];
	for (unsigned int i = 1; i < expression.size() - 1; i++){
		if(expression[i + 1] > 0){
			if (roots.first > 0) {
				cout << expression[i] << " * " << roots.first << "^" << i << " + ";
			}
			else {
				cout << expression[i] << " * (" << roots.first << ")^" << i << " + ";
			}
				
		}
		else{
			if (roots.first > 0){
				cout << expression[i] << " * " << roots.first << "^" << i;
			}
			else{
				cout << expression[i] << " * (" << roots.first << ")^" << i;
			}
		}
			
	}
	cout << expression[expression.size() - 1] << "x^" << expression.size() - 1;
	cout << " = " << values.first << endl;

	cout << "- f(" << roots.second << ") = ";
	expression[1] > 0 ?
		cout << expression[0] << " + " :
		cout << expression[0];
	for (unsigned int i = 1; i < expression.size() - 1; i++) {
		if (expression[i + 1] > 0) {
			if (roots.second > 0) {
				cout << expression[i] << " * " << roots.second << "^" << i << " + ";
			}
			else {
				cout << expression[i] << " * (" << roots.second << ")^" << i << " + ";
			}

		}
		else {
			if (roots.second > 0) {
				cout << expression[i] << " * " << roots.second << "^" << i;
			}
			else {
				cout << expression[i] << " * (" << roots.second << ")^" << i;
			}
		}

	}
	cout << expression[expression.size() - 1] << "x^" << expression.size() - 1;
	cout << " = " << values.second << endl << endl;

}

void displayMaxMin(pair<double, double> const& values, pair<double, double> const& edgeValues, pair<double, double> const& roots)
{
	cout << "max = MAX(" << values.first << ", " << values.second << ", " << edgeValues.first
		<< ", " << edgeValues.second << ") = "  << " , x = " << " ;" << endl;

	cout << "- min = MIN(" << values.first << ", " << values.second << ", " << edgeValues.first
		<< ", " << edgeValues.second << ") = " << " , x = " << " ;" << endl << endl;
}

void displayFunctionValues(vector<int> const& expression, vector<double>  const& values)
{
	vector<int> numbers;
	for (unsigned int i = 0; i < values.size(); i++)
	{
		int sum = 0;
		for (unsigned int j = 0; j < expression.size(); j++)
		{
			sum += expression[j] * pow(values[i], j);
		}
		numbers.push_back(sum);
		cout << sum << endl;
	}

	int sum = 0;
	for (int x: numbers)
	{
		sum += x;
	}
	cout << "avg : " << sum / 4 << endl;
}

void classicTheoryOfOptimization()
{
	cout << "Enter the amount of cofficients: ";
	int amount = 0;
	cin >> amount;
	pair<double, double> edgeValues = make_pair(-10, 53);

	cout << "Enter cofficients: " << endl;
	vector<int> coefs = setCoefs(amount);
	displayExpression(coefs);

	vector<int> firstDerivative = computeDerivative(coefs);
	cout << "First derivative : " << endl;
	displayExpression(firstDerivative);

	pair<double, double> roots = findRoots(firstDerivative);
	displayRoots(roots);

	vector<int> secondDerivative = computeDerivative(firstDerivative);
	cout << "Second derivative : " << endl;
	displayExpression(secondDerivative);

	pair<double, double> extremas = computeExtremas(roots, secondDerivative);
	displayExtremas(extremas, roots, secondDerivative);

	pair<double, double> values = computeFunction(roots, coefs);
	displayFunctionValues(roots, coefs, values);

	pair<double, double> maxValues = computeFunction(edgeValues, coefs);
	displayFunctionValues(edgeValues, coefs, maxValues);

	displayMaxMin(values, maxValues, roots);

	vector<double> numbers1{ 17,24,-6,47 };
	vector<double> numbers2{ 8,33,31,48 };
	
	displayFunctionValues(coefs, numbers1);
	displayFunctionValues(coefs, numbers2);

}

int main()
{
	classicTheoryOfOptimization();

}