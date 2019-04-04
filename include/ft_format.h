#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include <sys/types.h>
# include <inttypes.h>

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
	uint8_t		has_prefix : 1;
	uint8_t		is_upper : 1;
	uint8_t		has_sep : 1;
	uint8_t		has_dec_point : 1;
	uint8_t		length_mod : 4;
	uint32_t	left_field_width;
	uint32_t	right_field_width;
	uint32_t	zero_field_width;
	uint32_t	zero_precision;
	char		pos_sign;
	uint8_t		type;
}				t_format;

int				ft_format_parse(t_format *f, const char *format);

#endif
