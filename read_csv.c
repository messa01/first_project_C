#include <stdio.h>

int main() {
	FILE *file =fopen("users.csv", "r");
	if (file == NULL) {
		perror("MA BELLE Error opening file");
		return 1;
	}

	char line[256];
	while (fgets(line, sizeof(line), file)) {
		printf("%s", line);
	}

	fclose(file);
	return 0;

}
