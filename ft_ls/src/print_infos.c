#include "../includes/ft_ls.h"

// Fonction qui affiche le nmb d'hardlinks pour chaque fichiers

void	print_hardlinks(char *file, struct stat fs)
{
	ft_printf("%4d", fs.st_nlink);
}

// Fonction qui m'affiche la taille en bytes de mon fichier

void print_size(char *file, struct stat fs)
{
	ft_printf(" %6lld", (long long) fs.st_size);
}

// Fonction qui affiche le proprietaire/grp pour chaque fichiers

void	print_owner(char *file, struct stat fs)
{
	struct passwd *pwd;

	pwd = getpwuid(fs.st_uid);
	ft_printf(" %s ", pwd->pw_name);
	ft_printf(" %s", ((getgrgid(pwd->pw_gid)->gr_name)));
}

// Fonction qui affiche les permissions de chaque fichiers
// Pas moi qui l'ait fait !!!

void	print_permissions(char *file, struct stat fs)
{
	ft_printf((S_ISDIR(fs.st_mode)) ? "d" : "-");
	ft_printf((fs.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((fs.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((fs.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((fs.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((fs.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((fs.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((fs.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((fs.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((fs.st_mode & S_IXOTH) ? "x " : "- ");
}

// Fonction qui m'affiche le mois, jour et heure de la derniere modif du fichiers

void	print_date(char *file, struct stat fs)
{
	char *coucoudate;

	coucoudate = (ctime(&fs.st_mtime));
 	ft_printf(" %s", ft_strsub(coucoudate, 4, 3));
	ft_printf(" %s", ft_strsub(coucoudate, 8, 2));
	ft_printf(" %s ", ft_strsub(coucoudate, 11, 5));
}
