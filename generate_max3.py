from llvmlite import ir, binding

# Cria um módulo
module = ir.Module(name="max3_module")
module.triple = binding.get_default_triple()

# Define tipo da função: int64_t(int64_t, int64_t, int64_t)
func_ty = ir.FunctionType(ir.IntType(64), [ir.IntType(64), ir.IntType(64), ir.IntType(64)])

# Cria a função
function = ir.Function(module, func_ty, name="max3")

# Nomeia os parâmetros
a, b, c = function.args
a.name = "a"
b.name = "b"
c.name = "c"

# Cria o bloco de entrada
block = function.append_basic_block(name="entry")
builder = ir.IRBuilder(block)

# if (a > b)
cmp_ab = builder.icmp_signed('>', a, b)
max_ab = builder.select(cmp_ab, a, b)

# if (max_ab > c)
cmp_abc = builder.icmp_signed('>', max_ab, c)
max_abc = builder.select(cmp_abc, max_ab, c)

# Retorna o maior valor
builder.ret(max_abc)

# Salva o IR textual
with open("max3.ll", "w") as f:
    f.write(str(module))

# Salva o bitcode
binding.initialize()
binding.initialize_native_target()
binding.initialize_native_asmprinter()

llvm_module = binding.parse_assembly(str(module))
llvm_module.verify()

with open("max3.bc", "wb") as f:
    f.write(llvm_module.as_bitcode())

print("Gerado max3.ll e max3.bc com sucesso!")
