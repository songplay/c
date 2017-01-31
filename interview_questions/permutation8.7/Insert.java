String InsertChar(String s, char c, int i)
{
	String start = s.substr(0, i);
	String end = s.substr(i);
	return (start + c + end);
}
