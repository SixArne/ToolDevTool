#include <iostream>
#include "src/OBJParser.h"

int main( int argc, char** argv )
{
	std::string input_file;
	std::string output_file;
	bool reverse = false;
	bool reverse_was_found = false;

	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg == "-i" && i + 1 < argc) {
			input_file = argv[i + 1];
			i++;
		}
		else if (arg == "-o" && i + 1 < argc) {
			output_file = argv[i + 1];
			i++;
		}
		else if (arg == "-r") {
			reverse = true;
			reverse_was_found = true;
		}
		else {
			std::cout << "Invalid argument: " << arg << std::endl;
			std::cout << "Usage: " << argv[0] << " [-i input_file] [-o output_file] [-r]" << std::endl;
			return 1;
		}
	}

	if (!reverse_was_found) {
		std::cout << "Warning: Recursive flag not found. Processing only the top-level directory." << std::endl;
	}

	if (input_file.empty() || output_file.empty()) {
		std::cout << "Missing input or output file." << std::endl;
		std::cout << "Usage: " << argv[0] << " [-i input_file] [-o output_file] [-r]" << std::endl;
		return 1;
	}

	Util::OBJParser parser{};
	if (reverse)
	{
		parser.ReadBinaryOBJFile(input_file);
		parser.WriteToText(output_file);
	}
	else
	{
		parser.ReadTextOBJFile(input_file);
		parser.WriteToBinary(output_file);
	}

	return 0;
}