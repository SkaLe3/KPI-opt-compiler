#pragma once

#include <string>
#include <cstdint>

enum class EErrorInstigator : uint8_t
{
	FileIO,
	Compiler,
	Lexer,
	Parser,
	CodeGenerator
};

enum class EErrorType : uint8_t
{
	SyntaxError,
	SemanticError,
	DriverError,
	BuildError,
	None
};

class Error
{
public:
	Error(const std::string& msg, size_t line, size_t pos, EErrorInstigator inst, EErrorType type);
	std::string GetMessage();
	std::string GetInstigator();
	std::string GetType();
	std::string GetLine();
	std::string GetPosition();

	EErrorInstigator GetEnumInstigator();


private:
	static std::string InstigatorToString(EErrorInstigator instigator);
	static std::string TypeToString(EErrorType type);

protected:
	size_t m_Line;
	size_t m_Position;

	EErrorInstigator m_Instigator;
	EErrorType m_ErrorType;

	std::string m_Message;
};
