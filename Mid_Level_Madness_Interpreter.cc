#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#define context vector<string> lines, vector<pair<int, string>> vars, int i
using namespace std;
// written by Sublics (voyagess)

vector<pair<int, string>> var_init(context) {
	string nmv = lines[i];
	nmv.erase(nmv.begin());
	vars.push_back(make_pair(0, nmv));
	return vars;
}

void out_operation(context) {
	string nmv = lines[i];
	nmv.erase(nmv.begin());
	for (pair<int, string> q : vars) {
		if (q.second == nmv) {
			cout << q.first << '\n';
			return;
		}
	}
}

vector<pair<int, string>> add_operation(context) {
	string nmv = lines[i];
	nmv.erase(nmv.begin());
	for (int q = 0; q < vars.size(); q++) {
		if (vars[q].second == nmv) {
			vars[q].first++;
			return vars;
		}
	}
	return vars;
}

vector<pair<int, string>> subtract_operation(context) {
	string nmv = lines[i];
	nmv.erase(nmv.begin());
	for (int q = 0; q < vars.size(); q++) {
		if (vars[q].second == nmv) {
			vars[q].first--;
			return vars;
		}
	}
	return vars;
}

void out_char_operation(context) {
	string nmv = lines[i];
	nmv.erase(nmv.begin());
	for (pair<int, string> x : vars) {
		if (x.second == nmv) {
			char letter = x.first == 1 ? 'a' : x.first == 2 ? 'b' : x.first == 3 ? 'c' : x.first == 4 ? 'd' : x.first == 5 ? 'e' : x.first == 6 ? 'f' : x.first == 7 ? 'g' : x.first == 8 ? 'h' : x.first == 9 ? 'i' : x.first == 10 ? 'j' : x.first == 11 ? 'k' : x.first == 12 ? 'l' : x.first == 13 ? 'm' : x.first == 14 ? 'n' : x.first == 15 ? 'o' : x.first == 16 ? 'p' : x.first == 17 ? 'q' : x.first == 18 ? 'r' : x.first == 19 ? 's' : x.first == 20 ? 't' : x.first == 21 ? 'u' : x.first == 22 ? 'v' : x.first == 23 ? 'w' : x.first == 24 ? 'x' : x.first == 25 ? 'y' : x.first == 26 ? 'z' :  x.first == 27 ? ' ' : '\n';
			cout << letter;
			return;
		}
	}
}

pair<int, vector<pair<int, string>>> jump_operation(context) {
	string nmv = lines[i];
	nmv.erase(nmv.begin());
	string tvar = " ";
	string num;
	string linenum;
	bool tvr = false;
	bool nm = false;
	for (int q = 1; q < nmv.size(); q++) {
		if (nmv[q] != ' ' && !tvr) {
			tvar += nmv[q];
			continue;
		}
		else {
			if (!tvr) {
				tvr = true;
				continue;
			}
			if (nmv[q] != ' ' && !nm) {
				num += nmv[q];
				continue;
			}
			else {
				if (!nm) {
					nm = true;
					continue;
				}
				if (nmv[q] != '\n' && nm && tvr) {
					linenum += nmv[q];
				}
			}
		}
	}
	int linee = stoi(linenum);
	int comp;

	bool found = false;
	for (pair<int, string> x : vars) {
		if (" " + num == x.second) {
			comp = x.first;
			found = true;
			break;
		}
	}
	if (!found) {
		comp = stoi(num);
	}

	if (linee == i && lines[i - 1][0] == '+') {
		for (int q = 0; q < vars.size(); q++) {
			if (vars[q].second == tvar && vars[q].first < comp) {
				vars[q].first = comp;
				return make_pair(i, vars);
			}
		}
	}

	for (pair<int, string> q : vars) {
		if (q.second == tvar) {
			if (q.first != comp) {
				i = linee - 2;
				break;
			}
		}
	}
	return make_pair(i, vars);
}

void execute_lines(vector<string> lines, vector<pair<int, string>> vars) {
	for (int i = 0; i < lines.size(); i++) {
		switch (lines[i][0]) {
		case '=':
			//cout << "DEBUG : INIT :\n";
			vars = var_init(lines, vars, i);
			break;
		case '<':
			//cout << "DEBUG : OUT :\n";
			out_operation(lines, vars, i);
			break;
		case '+':
			//cout << "DEBUG : ADD :\n";
			vars = add_operation(lines, vars, i);
			break;
		case '-':
			//cout << "DEBUG : MINUS :\n";
			vars = subtract_operation(lines, vars, i);
			break;
		case ':':
			//cout << "DEBUG : CHAR_OUT :\n";
			out_char_operation(lines, vars, i);
			break;
		case 'j':
			//cout << "DEBUG : JUMP :\n";
			pair<int, vector<pair<int, string>>> returns = jump_operation(lines, vars, i);
			i = returns.first;
			vars = returns.second;
			break;
		}
	}
}

int main() {
	cin.tie(nullptr);
	ifstream Read_file("input.mlm");
	vector<string> lines;
	vector<pair<int, string>> vars;
	string t;
	while (getline(Read_file, t)) {
		lines.push_back(t);
	}
	Read_file.close();
	execute_lines(lines, vars);

	return 0;
}