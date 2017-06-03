import string

class SuperFormatter(string.Formatter):
    def format_field(self, value, spec):
        if spec.startswith('repeat'):
            template = spec.partition(':')[-1]
            if type(value) is dict:
                value = value.items()
            return ''.join([template.format(item=item) for item in value])
        else:
            return super(SuperFormatter, self).format.field(value, spec)


sf = SuperFormatter()
print sf.format('''Table of contents:
        {chapters:repeat:Chapter {{item}}
        }''', chapters=["I","II","III","IV"])

