import equation_parser as ep
import sys
import os
from print_functions import *


lefts = []
rights = []

variables = []
diff_variables = []
params = []

params.append("dt")


command = 1

f = open(sys.argv[1], "r")

lines = f.readlines()
aux = lines[0].split(" ")

model_name = aux[0]
min_v = aux[1]
max_v = aux[2].replace("\n", "")

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
print(diff_variables)

if not os.path.exists("model_library/neuron/"+model_name):
    os.makedirs("model_library/neuron/"+model_name)

output_file = open("model_library/neuron/"+model_name+"/nm_"+model_name.lower()+".c", "w+")
print_source_begin(diff_variables, variables, params, model_name, output_file)

for i in range(len(lefts)):
	params = ep.parse(diff_variables, variables, params, model_name, lefts[i]+" = "+rights[i], output_file)

print_source_funcs(diff_variables, variables, params, model_name, min_v, max_v, output_file)
output_file.close()


output_file = open("model_library/neuron/"+model_name+"/nm_"+model_name.lower()+".h", "w+")
print_header_file(diff_variables, variables, params, model_name, output_file)
output_file.close()

output_file = open("model_library/neuron/"+model_name+"/main_"+model_name.lower()+".c", "w+")
print_main_file(diff_variables, variables, params, model_name, output_file)
output_file.close()

output_file = open("model_library/neuron/"+model_name+"/nm_gui_"+model_name.lower()+".cpp", "w+")
print_cpp_source_file(diff_variables, variables, params, model_name, output_file)
output_file.close()

output_file = open("model_library/neuron/"+model_name+"/nm_gui_"+model_name.lower()+".h", "w+")
print_cpp_header_file(diff_variables, variables, params, model_name, output_file)
output_file.close()

output_file = open("model_library/neuron/"+model_name+"/nm_xml_"+model_name.lower()+".h", "w+")
print_xml_header_file(diff_variables, variables, params, model_name, output_file)
output_file.close()

output_file = open("model_library/neuron/"+model_name+"/nm_xml_"+model_name.lower()+".c", "w+")
print_xml_source_file(diff_variables, variables, params, model_name, output_file)
output_file.close()