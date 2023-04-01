#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

namespace Util
{
	struct Vertex
	{
		float x{};
		float y{};
		float z{};
	};

	struct Normal
	{
		float x{};
		float y{};
		float z{};
	};
	
	struct Face
	{
		int v1{};
		int v2{};
		int v3{};
	};

	struct OBJData
	{
		int vertexCount{};
		std::vector<Vertex> vertices{};

		int normalCount{};
		std::vector<Normal> normals{};

		int faceCount{};
		std::vector<Face> faces{};
	};

	class OBJParser
	{
	public:
		OBJParser();

		void ReadTextOBJFile(const std::string& filenamePath);
		void ReadBinaryOBJFile(const std::string& filenamePath);
		void WriteToBinary(const std::string& filename);
		void WriteToText(const std::string& filename);

		std::string Test() { return "test"; };

	private:
		void ParseVerticesLine(std::string& line, size_t charPositionToPrune);
		void ParseNormalsLine(std::string& line, size_t charPositionToPrune);
		void ParseFacesLine(std::string& line, size_t charPositionToPrune);
	
		void SplitString(std::vector<std::string>& output, std::string& input, const std::string& delimiter);
		
		const std::string m_Filename{};
		OBJData m_OBJData{};
		bool m_FileIsValid{false};
	};
}


#endif
