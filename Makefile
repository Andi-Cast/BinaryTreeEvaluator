CXX = g++

CXXFLAGS = -std=c++11

EXE = assignment4

SRC = driver.cpp Binary_Expr_Node.cpp Number_Node.cpp Addition_Node.cpp Subtraction_Node.cpp Multiplication_Node.cpp Division_Node.cpp Modulus_Node.cpp Expr_Tree_Builder.cpp Calculator.cpp Eval_Visitor.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXE)

Test: driver.o
	g++ -std=c++11 -o driver.o Test

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(EXE)

# Run the executable
run: $(EXE)
	./$(EXE)