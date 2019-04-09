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
	uint8_t	flags;
	int32_t	field_width;
	int32_t	precision;
	int8_t	length_mod;
	uint8_t	type;
	uint8_t	upper;
}				t_format;

ssize_t			ft_format_parse(t_format *f, const char *format);
void			ft_format_set_flag(t_format *f, const char *flag);
void			ft_format_add_length_mod(t_format *f, const char *length_mod);
void			ft_format_set_type(t_format *f, const char *type);

size_t			ft_format_left_padding(t_format *f);
char			ft_format_sign(t_format *f, int is_neg);
const char		*ft_format_prefix(t_format *f);
size_t			ft_format_zero_padding(t_format *f);
char			ft_format_separator(t_format *f);
size_t			ft_format_precision(t_format *f);
size_t			ft_format_right_padding(t_format *f);
uint8_t			ft_format_show_dec(t_format *f);
uint8_t			ft_format_lenmod(t_format *f);
uint8_t			ft_format_type(t_format *f);

#endif
