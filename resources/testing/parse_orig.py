#!/usr/bin/python3
file="dump_orig"
with open(file) as f:
	data = f.readlines()
	result = list()
	i = 0
	while i < len(data):
		if data[i][0] == ' ':
			data.pop(i)
		i += 1
	i = 1
	l = len(data)
	result.append(data[0][:-1])
	while data[i][0] == '*':
		result.append(data[i][:-1])
		i += 1
	while i < l:
		if data[i][0] == 'P':
			tmp = data[i - 1].split()
			nb = tmp[-1]
			while data[i][0] == 'P':
				new = f"[{nb}]\t{data[i][:-1]}"
				result.append(new)
				i += 1
		if i == l - 1:
			k = 1
			while data[-k][0] != 'I':
				k += 1
			tmp = data[-k].split()
			nb = tmp[-1]
			tmp = data[i].split()
			name = " ".join(tmp[2:-3])
			new = f"[{nb}] Player ({tmp[1][:-1]}) {name[1:-2]} won"
			result.append(new)
		i += 1
	for line in result:
		# tmp = line.split()
		# if tmp[-2] == 'live' and int(tmp[-1]) < 0:
		# 	l = len(tmp[-1])
		# 	new = f"{line[:-l]}{-1 * int(tmp[-1])}"
		# 	print(new)
		# else:
		print(line)