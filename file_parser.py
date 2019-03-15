import equation_parser as ep
import sys


def print_main_funcs(diff_variables, variables, params, model_name, output_file):
	label_upper = "NM_"+model_name.upper()+"_"
	label_lower = "nm_"+model_name.lower()+"_"

	output_file.write("void "+label_lower+"f (double * vars, double * ret, double * params, double syn) {\n")

	output_file.write("\tparams["+label_upper+"SYN] = syn;\n\n")

	for diff_var in diff_variables:
		#Falta añadir el input sinaptico
		output_file.write("\tret["+label_upper+diff_var.upper()+"] = "+label_lower+diff_var+"(vars, params);\n")

	output_file.write("}\n")


def print_header_file(diff_variables, variables, params, model_name, output_file):
	label_upper = "NM_"+model_name.upper()+"_"
	label_lower = "nm_"+model_name.lower()+"_"

	output_file.write("\n\n#define "+label_upper+"N_VARS %d\n"%(len(diff_variables)))
	output_file.write("// Variables\n")
	for i in range(len(diff_variables)):
		output_file.write("#define "+label_upper+diff_variables[i].upper()+" %d\n"%(i))

	output_file.write("\n\n#define "+label_upper+"N_PARAMS %d\n"%(len(params)))
	output_file.write("// Parameters\n")
	for i in range(len(params)):
		output_file.write("#define "+label_upper+params[i].upper()+" %d\n"%(i))



lefts = []
rights = []

variables = []
diff_variables = []
params = []


command = 1

f = open(sys.argv[1], "r")

lines = f.readlines()

model_name = lines[0].replace("\n", "")

for line in lines[1:]:
	aux = line.split("=")
	aux_left = aux[0].replace("\n", "")
	if (aux_left[-1] == " "):
		aux_left = aux_left[:-1]
	aux_right = aux[1].replace("\n", "")

	if "d/dt" in aux_left:
		aux_left = aux_left.split(" ")[1]

		if (aux_left in diff_variables) or (aux_left in variables):
			print("Already existing variable")
			continue
		else:
			diff_variables.append(aux_left)
	else:
		if (aux_left in diff_variables) or (aux_left in variables):
			print("Already existing variable")
			continue
		else:
			variables.append(aux_left)


	if aux_left in lefts:
		print("Already existing variable")
	else:
		lefts.append(aux_left)

		rights.append(aux_right)

		print(lefts[-1]+" = "+rights[-1])

f.close()

print(variables)

output_file = open("nm_"+model_name.lower()+".c", "w+")

output_file.write("#include \"nm_"+model_name.lower()+".h\"\n\n")

for i in range(len(lefts)):
	params = ep.parse(diff_variables, variables, params, model_name, lefts[i]+" = "+rights[i], output_file)

print_main_funcs(diff_variables, variables, params, model_name, output_file)

output_file.close()

output_file = open("nm_"+model_name.lower()+".h", "w+")


print_header_file(diff_variables, variables, params, model_name, output_file)

output_file.close()





'''
while (command == 1):
	command = int(input('\n0. Exit\n1. New equation\n2. Parse\n> '))

	if command != 1:
		break

	try:
	    aux_left = input('left > ')
	except EOFError:
	    break


	if "d/dt" in aux_left:
		aux_left = aux_left.split(" ")[1]

		if (aux_left in diff_variables) or (aux_left in variables):
			print("Already existing variable")
			continue
		else:
			diff_variables.append(aux_left)
	else:
		if (aux_left in diff_variables) or (aux_left in variables):
			print("Already existing variable")
			continue
		else:
			variables.append(aux_left)


	if aux_left in lefts:
		print("Already existing variable")
	else:
		lefts.append(aux_left)

		try:
		    aux_right = input('right > ')
		except EOFError:
		    break

		rights.append(aux_right)

		print(lefts[-1]+" = "+rights[-1])


if command == 2:

	for i in range(len(lefts)):
		params = ep.parse(diff_variables, variables, params, "Wang_1993", lefts[i]+" = "+rights[i])

	print_main_funcs(diff_variables, variables, params, "Wang_1993")

'''