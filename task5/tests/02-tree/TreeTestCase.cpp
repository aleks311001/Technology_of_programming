//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem.hpp>

TEST(tree_test, test1) {    
    auto temp_dir = boost::filesystem::temp_directory_path();
    auto temp = boost::filesystem::unique_path();
    temp_dir /= temp;
    
    ASSERT_THROW(GetTree(temp_dir.native(), true), std::invalid_argument);
    boost::filesystem::create_directory(temp_dir);
    
    auto dir = boost::filesystem::unique_path();
    dir = temp_dir / dir;
    boost::filesystem::create_directory(dir);
    
    auto file_name = boost::filesystem::unique_path();
    auto file_path = dir / file_name;
    boost::filesystem::ofstream tmp_file(file_path);
    
    ASSERT_THROW(GetTree(file_path.native(), true), std::invalid_argument);
    ASSERT_FALSE(GetTree(temp_dir.native(), true) == GetTree(temp_dir.native(), false));
    
    boost::filesystem::remove_all(temp_dir);
}
