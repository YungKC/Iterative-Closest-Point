#include <iostream>
#include "pointcloud.h"
#include <cstring>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtx/string_cast.hpp>

Pointcloud::Pointcloud(string filename, float scale) {
    cout << "Reading scene from " << filename << " ..." << endl;
    cout << " " << endl;
    char* fname = (char*)filename.c_str();
    fp_in.open(fname);
    if (!fp_in.is_open()) {
        cout << "Error reading from file - aborting!" << endl;
        throw;
    }
	int i = 0;
    while (fp_in.good()) {
        string line;
        utilityCore::safeGetline(fp_in, line);
        if (!line.empty()) {
            vector<string> tokens = utilityCore::tokenizeString(line);
//			glm::vec4 pt(atof(tokens[2].c_str()), atof(tokens[0].c_str()), atof(tokens[1].c_str()), 1);
            glm::vec4 pt(atof(tokens[0].c_str())*scale, atof(tokens[1].c_str())*scale, atof(tokens[2].c_str())*scale, 1);
			points.push_back(pt);
        }
    }
}
