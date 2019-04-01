#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include <sys/types.h>

# define ALPHA_OCT "01234567"
# define ALPHA_DEC "0123456789"
# define ALPHA_HEX_UP "0123456789ABCDEF"
# define ALPHA_HEX_LO "0123456789abcdef"
# define ALPHA_BIN "01"

# define PREFIX_OCT "0"
# define PREFIX_HEX_LO "0x"
# define PREFIX_HEX_UP "0X"
# define PREFIX_BIN "0b"
# define PREFIX_DEC ""

# define DEFAULT_DEC_SEPFREQ 3
# define DEFAULT_HEX_SEPFREQ 2
# define DEFAULT_OCT_SEPFREQ 4
# define DEFAULT_BIN_SEPFREQ 8

# define DEFAULT_DEC_SEP '\''
# define DEFAULT_SEP ':'

typedef struct	s_format
{
	char	flag[7];
	size_t	field_width;
	int		precision;
	char	length_mod[2];
	char	type;
}				t_format;

int				ft_format_parse(t_format *f, const char *format);

#endif
