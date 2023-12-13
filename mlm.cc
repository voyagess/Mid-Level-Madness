#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


string get_all_lines(string dir) {
	ifstream file(dir);
	string data;
	char temp;
	while (file.get(temp)) {
		if (temp == '\n') {
			data += ';';
			continue;
		}
		data += temp;
	}
	if (data.back() != ';') {
		data += ';';
	}
	return data;
}


bool is_token(char q) {
	map<char, string> descriptors = {
		{'=', "VAR_DECLARATION"},
		{'+', "ADD_OPERATION"},
		{'-', "SUB_OPERATION"},
		{':', "CHAR_OUTPUT"},
		{'<', "INT_OUTPUT"},
		{'j', "JUMP_OPERATION"},
		{';', "END_LINE"}
	};
	if (descriptors.find(q) != descriptors.end()) {
		return true;
	}
	return false;
}


bool is_int(string s) {
	try {
		stoi(s);
		return true;
	}
	catch (const exception& e) {
		return false;
	}
}


struct Variable {
	string name;
	int value;
};


struct Variables {
	vector<Variable> variables;
};


struct Label {
	int location;
	string name;
};


struct Labels {
	vector<Label> labels;
};


class Token {
public:
	Token(string input) {
		value = input;
		tokenize(input);
	}


	string get_value() {
		return value;
	}

	string get_desc() {
		return descriptor;
	}

	void retokenize(string input) {
		value = input;
		tokenize(input);
	}

private:

	void tokenize(string input) {
		map<string, string> descr =
		{
			{"=", "VAR_DECLARATION"},
			{"+", "ADD_OPERATION"},
			{"-", "SUB_OPERATION"},
			{":", "CHAR_OUTPUT"},
			{"<", "INT_OUTPUT"},
			{"j", "JUMP_OPERATION"},
			{";", "END_LINE"}
		};

		if (descr.find(input) != descr.end()) {
			descriptor = descr.at(input);
		}
		else if (is_int(input)) {
			descriptor = "INT_LITERAL";
		}

		else {
			descriptor = "UNDEFINED";
		}
	}

	string value;
	string descriptor;
};


class Tokens {
public:
	void add_token(Token &t) {
		tokens.push_back(t);
	}

	void print_tokens() {
		for (auto& a : tokens) {
			cout << a.get_value() << " " << a.get_desc() << '\n';
		}
	}

	int size() {
		return tokens.size();
	}

	Token at(int index) {
		return tokens[index];
	}

	Token& mod_at(int index) {
		return tokens[index];
	}

	int get_line(int token_num) {
		int line_count = 0;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens.at(i).get_desc() == "END_LINE")
				line_count++;
			if (i == token_num) {
				return line_count;
			}
		}
		return -1; // out of range of tokens
	}

private:
	vector<Token> tokens;
};


Label make_label(int loc, string naame) {
	Label l;
	l.location = loc;
	l.name = naame;
	return l;
}


Token make_token(char q = ' ', string s = "") {
	if (s == "") {
		string r = "";
		r += q;
		Token a(r);
		return a;
	}
	else if (q == ' ') {
		Token a(s);
		return a;
	}
	return make_token(' ', "Error:-1");
}


Tokens tokenize_all_data(string &lines) {
	Tokens tokens;
	string current;

	for (char &i : lines) {
		current += i;

		if (current == " ") {
			current.clear();
		}

		if (is_token(i)) {
			Token l = make_token(i);
			current.pop_back();

			// finding a token after some time, tells us that we have reached the end of a variable declaration
			if (current != "" && current != " ") {
				Token a = make_token(' ', current);
				tokens.add_token(a);
				current.clear();
			}

			// add l after the fact because that is the order it is in the source mlm file
			tokens.add_token(l);

			continue;
		}

		else if (i == ' ') {
			if (current != "" && current != " ") {
				if (current.back() == ' ') {
					current.pop_back();
				}

				Token a = make_token(' ', current);
				tokens.add_token(a);
				current.clear();
			}
		}
	}

	return tokens;
}


void run_mlm(string dir) {
	string lines = get_all_lines(dir);
	Tokens tokens = tokenize_all_data(lines);

	Variables vars;
	Labels labls;

	for (int q = 0; q < tokens.size(); q++) {
		if (tokens.at(q).get_desc() == "UNDEFINED" && tokens.at(q + 1).get_desc() == "CHAR_OUTPUT") {	// we know we are working with a label
			labls.labels.push_back(make_label(q, tokens.at(q).get_value()));
			continue;
		}

		if (tokens.at(q).get_desc() == "JUMP_OPERATION" && tokens.at(q + 3).get_desc() != "INT_LITERAL") {
			int loc;
			for (int i = 0; i < labls.labels.size(); i++) {
				if (labls.labels[i].name == tokens.at(q + 3).get_value()) {
					tokens.mod_at(q + 3).retokenize(to_string(labls.labels[i].location));
					// cout << "once " << tokens.at(q + 3).get_value() << "  " << labls.labels[i].location << '\n';
					break;
				}
			}
		}
	}

	// tokens.print_tokens();

	// maybe add error handling here where you check that all the tokens make sense

	for (int q = 0; q < tokens.size(); q++) {
		if (tokens.at(q).get_desc() == "VAR_DECLARATION") {
			Variable v;
			v.name = tokens.at(q + 1).get_value();
			v.value = 0;
			vars.variables.push_back(v);

			// increment q here because we have already sone what we need to with q + 1
			q++;
			continue;
		}

		else if (tokens.at(q).get_desc() == "ADD_OPERATION") {

			int index = -1;
			for (int i = 0; i < vars.variables.size(); i++) {
				if (vars.variables[i].name == tokens.at(q + 1).get_value()) {
					vars.variables[i].value++;
					break;
				}
			}

			q++;
			continue;
		}

		else if (tokens.at(q).get_desc() == "SUB_OPERATION") {

			for (int i = 0; i < vars.variables.size(); i++) {
				if (vars.variables[i].name == tokens.at(q + 1).get_value()) {
					vars.variables[i].value--;
					break;
				}
			}

			q++;
			continue;
		}

		else if (tokens.at(q).get_desc() == "INT_OUTPUT") {

			for (int i = 0; i < vars.variables.size(); i++) {
				if (vars.variables[i].name == tokens.at(q + 1).get_value()) {
					cout << vars.variables[i].value;
					break;
				}
			}

			q++;
			continue;
		}

		else if (tokens.at(q).get_desc() == "CHAR_OUTPUT") {

			for (int index = 0; index < vars.variables.size(); index++) {
				if (vars.variables[index].name == tokens.at(q + 1).get_value()) {
					cout << (vars.variables[index].value == 1 ? "a" : vars.variables[index].value == 2 ? "b" : vars.variables[index].value == 3 ? "c" : vars.variables[index].value == 4 ? "d" : vars.variables[index].value == 5 ? "e" : vars.variables[index].value == 6 ? "f" : vars.variables[index].value == 7 ? "g" : vars.variables[index].value == 8 ? "h" : vars.variables[index].value == 9 ? "i" : vars.variables[index].value == 10 ? "j" : vars.variables[index].value == 11 ? "k" : vars.variables[index].value == 12 ? "l" : vars.variables[index].value == 13 ? "m" : vars.variables[index].value == 14 ? "n" : vars.variables[index].value == 15 ? "o" : vars.variables[index].value == 16 ? "p" : vars.variables[index].value == 17 ? "q" : vars.variables[index].value == 18 ? "r" : vars.variables[index].value == 19 ? "s" : vars.variables[index].value == 20 ? "t" : vars.variables[index].value == 21 ? "u" : vars.variables[index].value == 22 ? "v" : vars.variables[index].value == 23 ? "w" : vars.variables[index].value == 24 ? "x" : vars.variables[index].value == 25 ? "y" : vars.variables[index].value == 26 ? "z" : vars.variables[index].value == 27 ? "\n" : vars.variables[index].value == 28 ? "?" : vars.variables[index].value == 29 ? "." : vars.variables[index].value == 30 ? " " : vars.variables[index].value == 31 ? ";" : vars.variables[index].value == 32 ? "=" : vars.variables[index].value == 33 ? "!" : vars.variables[index].value == 34 ? "{" : vars.variables[index].value == 35 ? "}" : vars.variables[index].value == 36 ? "(" : vars.variables[index].value == 37 ? ")" : vars.variables[index].value == 38 ? "[" : vars.variables[index].value == 39 ? "]" : vars.variables[index].value == 40 ? "<" : vars.variables[index].value == 41 ? ">" : "#");
					break;
				}
			}

			q++;
			continue;
		}

		else if (tokens.at(q).get_desc() == "JUMP_OPERATION") {

			string location = tokens.at(q + 3).get_value();
			string comparison = tokens.at(q + 2).get_value();
			Variable comparator;
			for (int i = 0; i < vars.variables.size(); i++) {
				if (vars.variables[i].name == tokens.at(q + 1).get_value()) {
					comparator = vars.variables[i];
					break;
				}
			}

			// watch out for cases where comparator isn't valid

			if (!is_int(comparison)) {
				for (int i = 0; i < vars.variables.size(); i++) {
					if (vars.variables[i].name == comparison) {
						comparison = to_string(vars.variables[i].value);
						break;
					}
				}
			}

			if (is_int(location)) {

				int loc = stoi(location);
				if (comparator.value != stoi(comparison)) {
					q = loc;
					continue;
				}
			}

			q += 3;
		}

	}
}


int main(int argc, char *argv[]) {

	string dir = "input.mlm";

	if (argc == 2) {

		dir = argv[1];
		run_mlm(dir);
	}

	return 0;
}