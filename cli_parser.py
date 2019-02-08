import equation_parser as ep


def print_main_funcs(diff_variables, variables, params, model_name):
	label_upper = "NM_"+model_name.upper()+"_"
	label_lower = "nm_"+model_name.lower()+"_"

	print("void "+label_lower+"f (double * vars, double * ret, double * params, double syn) {")

	for diff_var in diff_variables:
		print("\tret["+label_upper+diff_var.upper()+"] = "+label_lower+diff_var+"(vars, params);")

	print("}")


lefts = []
rights = []

variables = []
diff_variables = []
params = []



command = 1

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