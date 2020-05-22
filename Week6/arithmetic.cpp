#include <iostream>
#include <cstring> 
using namespace std;

long long int Make_operation(long long int Operand_1, long long int Operand_2, char op) {
	if (op == '*')
		return Operand_1 * Operand_2;
	else if (op == '+')
		return Operand_1 + Operand_2;
	else if (op == '-')
		return Operand_1 - Operand_2;
}

long long int Maximize_The_Expre(const string &Expre) {
	int Len = Expre.size();
	int NumOfOperands = (Len + 1) / 2;

	long long int Mini[NumOfOperands][NumOfOperands];
	long long int Maxi[NumOfOperands][NumOfOperands];

	memset(Mini, 0, sizeof(Mini)); // initialize to 0
	memset(Maxi, 0, sizeof(Maxi)); // initialize to 0
	for (int i = 0; i < NumOfOperands; i++) {

		Mini[i][i] = stoll(Expre.substr(2 * i, 1));
		Maxi[i][i] = stoll(Expre.substr(2 * i, 1));
	}

	for (int s = 0; s < NumOfOperands - 1; s++) {
		for (int i = 0; i < NumOfOperands - s - 1; i++) {
			int j = i + s + 1;
			long long int MinValue = 9999999;
			long long int MaxValue = -9999999;

			for (int k = i; k < j; k++) {
				long long int a = Make_operation(Mini[i][k], Mini[k + 1][j], Expre[2 * k + 1]);
				long long int b = Make_operation(Mini[i][k], Maxi[k + 1][j], Expre[2 * k + 1]);
				long long int c = Make_operation(Maxi[i][k], Mini[k + 1][j], Expre[2 * k + 1]);
				long long int d = Make_operation(Maxi[i][k], Maxi[k + 1][j], Expre[2 * k + 1]);

				MinValue = min(MinValue, min(a, min(b, min(c, d))));
				MaxValue = max(MaxValue, max(a, max(b, max(c, d))));

			}
			Mini[i][j] = MinValue;
			Maxi[i][j] = MaxValue;
		}
	}

	return Maxi[0][NumOfOperands - 1];
}

int main() {
	string Expresion;
	cin >> Expresion;

	cout << Maximize_The_Expre(Expresion) << endl;
}