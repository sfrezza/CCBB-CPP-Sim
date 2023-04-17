#include <string>
#include <vector>

struct spaceVector
{
    std::string route;
    std::string space;
};

struct RowData
{
    int turnNumber;
    std::string playerColor;
    std::vector<spaceVector> endSpace;
    std::string mb1color;
    std::string mb2color;
    bool winsGame;
};

class CsvParser
{
public:
    // Take the name of the .csv file as a parameter
    CsvParser(const std::string &filename);

    // Get the vector of RowData objects
    std::vector<RowData> getData() const;

private:
    // Split a string by a delimiter and return a vector of strings
    std::vector<std::string> split(const std::string &s, char delimiter) const;

    // Convert a string to an int and return it
    int toInt(const std::string &s) const;

    // Convert a string to a bool and return it
    bool toBool(const std::string &s) const;

    // Store the data
    std::vector<RowData> data;
};