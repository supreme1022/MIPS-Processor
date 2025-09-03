#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

const int NUM_REG = 32;
const int NUM_MEM = 1024;

enum Instructions {ADD = 32, SUB = 34, AND = 36, OR = 37, SLT = 42, LW = 35, SW = 43, BEQ= 4, BNE = 5, ADDI = 8};

vector<int32_t> registers(NUM_REG,0);
vector<int32_t> memory(NUM_MEM,0);

struct instruction{
instruction type;
  int rs = 0, rt = 0, rd = 0;
  int imm = 0;
  int funct = 0;
  int address = 0; 
}; 

// function to convert hexadecimal to binary
bitset<32> hexToBinary(const string &hex){
  int32_t instruction = stoi(hex,nullptr, 16);
  return bitset<32>(instruction);
}

// decode a binary instruction

instruction decodeInstruction(bitset<32> instruction){
  Instruction instr;
  int32_t opcode = instruction.to_ulong() >> 26;
}

// execute a decoded instruction
if(opcode == 0) {
  // R-type
  instr.rs(BinInstr >> 21 & 0x1F).to_ulong();
  instr.rt(BinInstr >> 16 & 0x1F).to_ulong();
  instr.rd(BinInstr >> 11 & 0x1F).to_ulong();
  instr.funct(BinInstr & 0x3F).to_ulong();
  instr.type = R_TYPE;
} else {
  // I-type
  instr.rs(BinInstr >> 21 & 0x1F).to_ulong();
  instr.rt(BinInstr >> 16 & 0x1F).to_ulong();
  instr.imm(BinInstr & 0xFFFF).to_ulong();
  instr.type = I_TYPE;
}

}

// execute a r tpype instruction
void ExAdd(int32_t rs, int rt, int rd){ registers[rd] = registers[rs] + registers[rt];}
void ExSub(int32_t rs, int rt, int rd){ registers[rd] = registers[rs] - registers[rt];}
void ExAnd(int32_t rs, int rt, int rd){ registers[rd] = registers[rs] & registers[rt];} 
void ExOr(int32_t rs, int rt, int rd){ registers[rd] = registers[rs] | registers[rt];}
void ExSlt(int32_t rs, int rt, int rd){ registers[rd] = (registers[rs] < registers[rt]) ? 1 : 0;}
void ExMult(int32_t rs, int rt, int rd){ registers[rd] = registers[rs] * registers[rt];}

// execute a i type instruction
void ExAddi(int32_t rs, int rt, int imm){ registers[rt] = registers + imm;}
void ExBeq(int32_t rs, int rt, int imm){if(registers[rs] == registers[rt]) pc += imm;}
void ExBne(int32_t rs, int rt, int imm){if(registers[rs] != registers[rt])pc += imm;}
void ExLw(int32_t rs, int rt, int imm){int add = registers[rs] + imm; if(add >= 0 && add < NUM_MEM) registers[rt] = memory[add];}
void ExSw(int32_t rs, int rt, int imm){int add = registers[rs] + imm; if(add >= 0 && add < NUM_MEM) memory[add] = registers[rt];}

// execute a instruction  
void execute(instruction instr&pc){
  switch(instr.type){
    case ADD: ExAdd(instr.rs, instr.rt, instr.rd); break;
    case SUB: ExSub(instr.rs, instr.rt, instr.rd); break;
    case AND: ExAnd(instr.rs, instr.rt, instr.rd); break;  
    case OR: ExOr(instr.rs, instr.rt, instr.rd); break;  
    case SLT: ExSlt(instr.rs, instr.rt, instr.rd); break;
    case MULT: ExMult(instr.rs, instr.rt, instr.rd); break;
    case ADDI: ExAddi(instr.rs, instr.rt, instr.imm); break;
    case BEQ: ExBeq(instr.rs, instr.rt, instr.imm); break;
    case BNE: ExBne(instr.rs, instr.rt, instr.imm); break;
    case LW: ExLw(instr.rs, instr.rt, instr.imm); break;
    case SW: ExSw(instr.rs, instr.rt, instr.imm); break;
    default: cout << "Invalid instruction" << endl; break;
  }
  
}


int main (){
  int pc = 0;
  string hex;
  vector<instruction> program;
  bool done = true
  
  cout << "Enter hexadecimal instructions " << endl; 
  
  
  
  for(int i =0; i < = NUM_REG; i++){
   regster[i] = i;
  cout << "Register " << i << ": " << registers[i] << endl;
  }

while(done = true){
  cout << "Enter hexadecimal instruction: ";
  cin >> hex;
  bitset<32> instruction = hexToBinary(hex);
  Instruction instr = decodeInstruction(binaryInstruction);
  program.push_back(instr);

}

  while (pc < program.size()) {
      Instruction instr = program[pc];
      executeInstruction(instr, pc);

      pc++;
  }


   for(int i =0; i < NUM_REG; i++){
    cout << " Up dated register " << i << ": " << registers[i] << endl;
    }

}