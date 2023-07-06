# Draw a turing machine that accepts the language {3x | n >= 0}

from automata.tm.dtm import DTM
from automata.tm.dtm import DTMConfiguration
from automata.tm.dtm import DTMRulebook
from automata.tm.dtm import DTMRule
from automata.tm.dtm import DTMDesign

# Create a rulebook for the machine
rulebook = DTMRulebook([
    # State 1: Scan right looking for a 3
    DTMRule(1, '1', 2, '1', 'R'),
    DTMRule(1, '0', 1, '0', 'R'),
    DTMRule(1, '3', 1, '3', 'R'),
    DTMRule(1, '_', 2, '_', 'R'),

    # State 2: Scan right looking for a 3
    DTMRule(2, '1', 2, '1', 'R'),
    DTMRule(2, '0', 2, '0', 'R'),
    DTMRule(2, '3', 3, '3', 'R'),

    # State 3: Scan right looking for a 3
    DTMRule(3, '1', 3, '1', 'R'),
    DTMRule(3, '0', 3, '0', 'R'),
    DTMRule(3, '_', 4, '_', 'L'),

    # State 4: Scan left looking for a 3
    DTMRule(4, '1', 4, '1', 'L'),
    DTMRule(4, '0', 4, '0', 'L'),
    DTMRule(4, '3', 4, '3', 'L'),

    # State 5: Scan left looking for a 3
    DTMRule(5, '1', 5, '1', 'L'),
    DTMRule(5, '0', 5, '0', 'L'),
    DTMRule(5, '3', 5, '3', 'L'),
    DTMRule(5, '_', 1, '_', 'R')

])

# Create a design for the machine
design = DTMDesign(1, ['1', '1', '1', '0', '0', '0', '3', '3', '3'])

# Run the machine
print(design.is_accepting())
design.step()
print(design.is_accepting())
design.run()
print(design.is_accepting())
