addi	$s0,$0,104
sw		$s0,4($0)
addi	$s0,$0,12
sw		$s0,8($0)
addi	$s0,$0,92
sw		$s0,12($0)
addi	$s0,$0,80
sw		$s0,16($0)
addi	$s0,$0,76
sw		$s0,20($0)
addi	$s0,$0,68
sw		$s0,24($0)
addi	$s0,$0,56
sw		$s0,28($0)
addi	$s0,$0,108
sw		$s0,32($0)
addi	$s0,$0,64
sw		$s0,36($0)
addi	$s0,$0,4
sw		$s0,40($0)
addi	$s0,$0,16
sw		$s0,44($0)
addi	$s0,$0,116
sw		$s0,48($0)
addi	$s0,$0,28
sw		$s0,52($0)
addi	$s0,$0,96
sw		$s0,56($0)
addi	$s0,$0,44
sw		$s0,60($0)
addi	$s0,$0,8
sw		$s0,64($0)
addi	$s0,$0,20
sw		$s0,68($0)
addi	$s0,$0,40
sw		$s0,72($0)
addi	$s0,$0,88
sw		$s0,76($0)
addi	$s0,$0,72
sw		$s0,80($0)
addi	$s0,$0,32
sw		$s0,84($0)
addi	$s0,$0,100
sw		$s0,88($0)
addi	$s0,$0,52
sw		$s0,92($0)
addi	$s0,$0,120
sw		$s0,96($0)
addi	$s0,$0,24
sw		$s0,100($0)
addi	$s0,$0,60
sw		$s0,104($0)
addi	$s0,$0,84
sw		$s0,108($0)
addi	$s0,$0,112
sw		$s0,112($0)
addi	$s0,$0,48
sw		$s0,116($0)
addi	$s0,$0,36
sw		$s0,120($0)

#--------------

addi	$1,$0,23333
addi	$2,$0,23333
addi	$3,$0,23333
addi	$4,$0,23333
addi	$5,$0,23333
addi	$6,$0,23333
addi	$7,$0,23333
addi	$8,$0,23333
addi	$9,$0,23333
addi	$10,$0,23333
addi	$11,$0,23333
addi	$12,$0,23333
addi	$13,$0,23333
addi	$14,$0,23333
addi	$15,$0,23333
addi	$16,$0,23333
addi	$17,$0,23333
addi	$18,$0,23333
addi	$19,$0,23333
addi	$20,$0,23333
addi	$21,$0,23333
addi	$22,$0,23333
addi	$23,$0,23333
addi	$24,$0,23333
addi	$25,$0,23333
addi	$26,$0,23333
addi	$27,$0,23333
addi	$28,$0,23333
addi	$29,$0,23333
addi	$30,$0,23333
addi	$31,$0,23333

addi	$t0,$0,8
addi	$t2,$0,-12288

#--------------

addi	$31,$0,0
jal		TAG_0
addi	$31,$31,4
sw		$31,-8192($31)
TAG_0:
addu	$31,$t2,$31
jal		TAG_1
addi	$31,$31,4
sw		$31,-8192($31)
TAG_1:
addi	$31,$31,-12288
beq		$31,$31,TAG_2
sw		$31,4096($31)
sw		$31,4096($31)
TAG_2:

addi	$31,$0,16
jal		TAG_3
sw		$31,-8192($31)
lw		$31,-12288($31)
TAG_3:
addu	$31,$t2,$31
jal		TAG_4
lw		$31,-12288($31)
addi	$31,$31,4
TAG_4:
addi	$31,$31,4
beq		$31,$31,TAG_5
sw		$31,4096($31)
addi	$31,$31,4
TAG_5:

addi	$31,$0,16
jal		TAG_6
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_6:
addu	$31,$t2,$31
jal		TAG_7
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_7:
addi	$31,$31,4
beq		$31,$0,TAG_8
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_8:

addi	$31,$0,4
jal		TAG_9
addu	$31,$31,$t0
addi	$31,$31,4
TAG_9:
addu	$31,$t2,$31
jal		TAG_10
sw		$31,-8192($31)
addi	$31,$31,4
TAG_10:
addi	$31,$31,-12288
beq		$31,$0,TAG_11
addu	$31,$t0,$31
addi	$31,$31,4
TAG_11:

addi	$31,$0,4
jal		TAG_12
lw		$31,-12288($31)
addu	$31,$31,$t0
TAG_12:
addu	$31,$t0,$31
jal		TAG_13
sw		$31,-8192($31)
lw		$31,-12288($31)
TAG_13:
addi	$31,$31,-12288
addi	$t1,$31,0
beq		$t1,$31,TAG_14
lw		$31,0($31)
lw		$31,0($31)
TAG_14:

addi	$31,$0,8
jal		TAG_15
lw		$31,-12288($31)
addu	$31,$31,$t0
TAG_15:
addu	$31,$t0,$31
jal		TAG_16
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_16:
addi	$31,$31,-12288
addi	$t1,$31,0
beq		$t1,$31,TAG_17
addi	$31,$31,4
addu	$31,$t0,$31
TAG_17:

addi	$31,$0,28
jal		TAG_18
sw		$31,-8192($31)
addu	$31,$31,$t0
TAG_18:
addu	$31,$t2,$31
jal		TAG_19
addi	$31,$31,4
sw		$31,-8192($31)
TAG_19:
addi	$31,$31,-12288
addi	$t1,$31,1
beq		$31,$t1,TAG_20
lw		$31,0($31)
addu	$31,$t0,$31
TAG_20:

addi	$31,$0,24
jal		TAG_21
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_21:
addu	$31,$t2,$31
jal		TAG_22
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_22:
addi	$31,$31,-12288
addi	$t1,$31,1
beq		$31,$t1,TAG_23
addu	$31,$31,$t0
addu	$31,$t0,$31
TAG_23:

addi	$31,$0,24
jal		TAG_24
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_24:
addu	$31,$t2,$31
jal		TAG_25
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_25:
addi	$31,$31,4
addi	$31,$31,4

addi	$31,$0,0
jal		TAG_26
lw		$31,-12288($31)
addi	$31,$31,4
TAG_26:
addu	$31,$t0,$31
jal		TAG_27
addu	$31,$t0,$31
sw		$31,-8192($31)
TAG_27:
addi	$31,$31,-12288
addi	$31,$31,4

addi	$31,$0,12
jal		TAG_28
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_28:
addu	$31,$t0,$31
jal		TAG_29
addi	$31,$31,4
addu	$31,$31,$t0
TAG_29:
addi	$31,$31,-12288
la		$31,TAG_30
jr		$31
addu	$31,$31,$t0
addu	$31,$t0,$31
TAG_30:

addi	$31,$0,28
jal		TAG_31
addu	$31,$31,$t0
addu	$31,$t0,$31
TAG_31:
addu	$31,$t2,$31
jal		TAG_32
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_32:
addi	$31,$31,-12288
la		$31,TAG_33
jr		$31
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_33:

addi	$31,$0,28
jal		TAG_34
addu	$31,$t0,$31
addi	$31,$31,4
TAG_34:
addu	$31,$t2,$31
jal		TAG_35
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_35:
addi	$31,$31,-12288
la		$31,TAG_36
jalr	$t3,$31
lw		$31,-12288($31)
addu	$31,$31,$t0
TAG_36:

addi	$31,$0,8
jal		TAG_37
addu	$31,$t0,$31
lw		$31,-12288($31)
TAG_37:
addu	$31,$t2,$31
jal		TAG_38
addi	$31,$31,4
sw		$31,-8192($31)
TAG_38:
addi	$31,$31,-12288
la		$31,TAG_39
jalr	$t3,$31
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_39:

addi	$31,$0,12
jal		TAG_40
addi	$31,$31,4
sw		$31,-8192($31)
TAG_40:
addu	$31,$t2,$31
jal		TAG_41
addu	$31,$t0,$31
sw		$31,-8192($31)
TAG_41:
jal		TAG_42
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_42:
lw		$31,-12288($31)

addi	$31,$0,16
jal		TAG_43
addi	$31,$31,4
addu	$31,$t0,$31
TAG_43:
addu	$31,$t2,$31
jal		TAG_44
sw		$31,-8192($31)
addi	$31,$31,4
TAG_44:
jal		TAG_45
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_45:
lw		$31,-12288($31)

addi	$31,$0,24
jal		TAG_46
addi	$31,$31,4
addu	$31,$31,$t0
TAG_46:
addu	$31,$t2,$31
jal		TAG_47
addu	$31,$31,$t0
addu	$31,$t0,$31
TAG_47:
jal		TAG_48
sw		$31,-8192($31)
addi	$31,$31,4
TAG_48:
sw		$31,-8192($31)

addi	$31,$0,16
jal		TAG_49
sw		$31,-8192($31)
lw		$31,-12288($31)
TAG_49:
addu	$31,$t2,$31
jal		TAG_50
addi	$31,$31,4
addu	$31,$t0,$31
TAG_50:
jal		TAG_51
addu	$31,$t0,$31
lw		$31,-12288($31)
TAG_51:
sw		$31,-8192($31)

addi	$31,$0,16
jal		TAG_52
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_52:
addu	$31,$t2,$31
jal		TAG_53
sw		$31,-8192($31)
lw		$31,-12288($31)
TAG_53:
jal		TAG_54
addi	$31,$31,4
lw		$31,-12288($31)
TAG_54:
addu	$31,$t0,$31

addi	$31,$0,4
jal		TAG_55
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_55:
addu	$31,$t2,$31
jal		TAG_56
addu	$31,$t0,$31
addu	$31,$31,$t0
TAG_56:
jal		TAG_57
addi	$31,$31,4
addu	$31,$t0,$31
TAG_57:
addu	$31,$t0,$31

addi	$31,$0,24
jal		TAG_58
addi	$31,$31,4
addi	$31,$31,4
TAG_58:
addu	$31,$t2,$31
jal		TAG_59
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_59:
jal		TAG_60
addi	$31,$31,4
addu	$31,$31,$t0
TAG_60:
addu	$31,$31,$t0

addi	$31,$0,28
jal		TAG_61
addu	$31,$t0,$31
addi	$31,$31,4
TAG_61:
addu	$31,$t2,$31
jal		TAG_62
sw		$31,-8192($31)
lw		$31,-12288($31)
TAG_62:
jal		TAG_63
sw		$31,-8192($31)
addu	$31,$31,$t0
TAG_63:
addu	$31,$31,$t0

addi	$31,$0,28
jal		TAG_64
addi	$31,$31,4
sw		$31,-8192($31)
TAG_64:
addu	$31,$t2,$31
jal		TAG_65
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_65:
jal		TAG_66
addu	$31,$t0,$31
sw		$31,-8192($31)
TAG_66:
beq		$31,$31,TAG_67
sw		$31,-8192($31)
lw		$31,-12288($31)
TAG_67:

addi	$31,$0,28
jal		TAG_68
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_68:
addu	$31,$t2,$31
jal		TAG_69
addu	$31,$31,$t0
addi	$31,$31,4
TAG_69:
jal		TAG_70
addu	$31,$t0,$31
sw		$31,-8192($31)
TAG_70:
beq		$31,$31,TAG_71
addi	$31,$31,4
addu	$31,$t0,$31
TAG_71:

addi	$31,$0,4
jal		TAG_72
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_72:
addu	$31,$t2,$31
jal		TAG_73
addi	$31,$31,4
addi	$31,$31,4
TAG_73:
jal		TAG_74
addi	$31,$31,4
lw		$31,-12288($31)
TAG_74:
beq		$31,$0,TAG_75
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_75:

addi	$31,$0,0
jal		TAG_76
addu	$31,$t0,$31
sw		$31,-8192($31)
TAG_76:
addu	$31,$t2,$31
jal		TAG_77
addi	$31,$31,4
lw		$31,-12288($31)
TAG_77:
jal		TAG_78
lw		$31,-12288($31)
addu	$31,$31,$t0
TAG_78:
beq		$31,$0,TAG_79
addu	$31,$31,$t0
sw		$31,4096($31)
TAG_79:

addi	$31,$0,28
jal		TAG_80
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_80:
addu	$31,$t2,$31
jal		TAG_81
addu	$31,$t0,$31
addu	$31,$31,$t0
TAG_81:
jal		TAG_82
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_82:
addi	$t1,$31,0
beq		$t1,$31,TAG_83
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_83:

addi	$31,$0,16
jal		TAG_84
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_84:
addu	$31,$t0,$31
jal		TAG_85
addu	$31,$31,$t0
addu	$31,$t0,$31
TAG_85:
jal		TAG_86
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_86:
addi	$t1,$31,0
beq		$t1,$31,TAG_87
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_87:

addi	$31,$0,0
jal		TAG_88
lw		$31,-12288($31)
addi	$31,$31,4
TAG_88:
addu	$31,$t0,$31
jal		TAG_89
lw		$31,-12288($31)
addu	$31,$31,$t0
TAG_89:
jal		TAG_90
addi	$31,$31,4
addu	$31,$31,$t0
TAG_90:
addi	$t1,$31,1
beq		$31,$t1,TAG_91
addu	$31,$t0,$31
addu	$31,$31,$t0
TAG_91:

addi	$31,$0,0
jal		TAG_92
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_92:
addu	$31,$t2,$31
jal		TAG_93
addi	$31,$31,4
sw		$31,-8192($31)
TAG_93:
jal		TAG_94
sw		$31,-8192($31)
addi	$31,$31,4
TAG_94:
addi	$t1,$31,1
beq		$31,$t1,TAG_95
lw		$31,-12288($31)
addu	$31,$31,$t0
TAG_95:

addi	$31,$0,16
jal		TAG_96
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_96:
addu	$31,$t2,$31
jal		TAG_97
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_97:
jal		TAG_98
addi	$31,$31,4
addi	$31,$31,4
TAG_98:
addi	$31,$31,4

addi	$31,$0,28
jal		TAG_99
lw		$31,-12288($31)
addi	$31,$31,4
TAG_99:
addu	$31,$t0,$31
jal		TAG_100
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_100:
jal		TAG_101
addi	$31,$31,4
sw		$31,-8192($31)
TAG_101:
addi	$31,$31,4

addi	$31,$0,24
jal		TAG_102
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_102:
addu	$31,$t0,$31
jal		TAG_103
addi	$31,$31,4
lw		$31,-12288($31)
TAG_103:
jal		TAG_104
sw		$31,-8192($31)
addi	$31,$31,4
TAG_104:
la		$31,TAG_105
jr		$31
addu	$31,$t0,$31
addi	$31,$31,4
TAG_105:

addi	$31,$0,28
jal		TAG_106
addu	$31,$31,$t0
addi	$31,$31,4
TAG_106:
addu	$31,$t2,$31
jal		TAG_107
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_107:
jal		TAG_108
addi	$31,$31,4
addi	$31,$31,4
TAG_108:
la		$31,TAG_109
jr		$31
addu	$31,$31,$t0
addu	$31,$31,$t0
TAG_109:

addi	$31,$0,0
jal		TAG_110
lw		$31,-12288($31)
sw		$31,4096($31)
TAG_110:
addu	$31,$t0,$31
jal		TAG_111
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_111:
jal		TAG_112
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_112:
la		$31,TAG_113
jalr	$t3,$31
addi	$31,$31,4
addi	$31,$31,4
TAG_113:

addi	$31,$0,20
jal		TAG_114
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_114:
addu	$31,$t2,$31
jal		TAG_115
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_115:
jal		TAG_116
addu	$31,$31,$t0
addi	$31,$31,4
TAG_116:
la		$31,TAG_117
jalr	$t3,$31
addu	$31,$t0,$31
addu	$31,$31,$t0
TAG_117:

la		$t3,TAG_120
addi	$31,$0,16
jal		TAG_118
addi	$31,$31,4
addi	$31,$31,4
TAG_118:
addu	$31,$t2,$31
jal		TAG_119
sw		$31,-8192($31)
lw		$31,-12288($31)
TAG_119:
jalr	$31,$t3
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_120:
lw		$31,-12288($31)

la		$t3,TAG_123
addi	$31,$0,8
jal		TAG_121
addu	$31,$t0,$31
lw		$31,-12288($31)
TAG_121:
addu	$31,$t2,$31
jal		TAG_122
sw		$31,-8192($31)
addu	$31,$31,$t0
TAG_122:
jalr	$31,$t3
sw		$31,-8192($31)
addu	$31,$31,$t0
TAG_123:
lw		$31,-12288($31)

la		$t3,TAG_126
addi	$31,$0,8
jal		TAG_124
addu	$31,$31,$t0
addi	$31,$31,4
TAG_124:
addu	$31,$t2,$31
jal		TAG_125
sw		$31,-8192($31)
addu	$31,$31,$t0
TAG_125:
jalr	$31,$t3
addi	$31,$31,4
addu	$31,$31,$t0
TAG_126:
sw		$31,-8192($31)

la		$t3,TAG_129
addi	$31,$0,16
jal		TAG_127
addi	$31,$31,4
lw		$31,-12288($31)
TAG_127:
addu	$31,$t2,$31
jal		TAG_128
addu	$31,$31,$t0
addi	$31,$31,4
TAG_128:
jalr	$31,$t3
addu	$31,$31,$t0
addi	$31,$31,4
TAG_129:
sw		$31,-8192($31)

la		$t3,TAG_132
addi	$31,$0,20
jal		TAG_130
addu	$31,$t0,$31
lw		$31,-12288($31)
TAG_130:
addu	$31,$t2,$31
jal		TAG_131
addi	$31,$31,4
sw		$31,-8192($31)
TAG_131:
jalr	$31,$t3
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_132:
addu	$31,$t0,$31

la		$t3,TAG_135
addi	$31,$0,12
jal		TAG_133
sw		$31,-8192($31)
addi	$31,$31,4
TAG_133:
addu	$31,$t2,$31
jal		TAG_134
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_134:
jalr	$31,$t3
addu	$31,$31,$t0
addu	$31,$t0,$31
TAG_135:
addu	$31,$t0,$31

la		$t3,TAG_138
addi	$31,$0,20
jal		TAG_136
addi	$31,$31,4
lw		$31,-12288($31)
TAG_136:
addu	$31,$t2,$31
jal		TAG_137
sw		$31,-8192($31)
addi	$31,$31,4
TAG_137:
jalr	$31,$t3
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_138:
addu	$31,$31,$t0

la		$t3,TAG_141
addi	$31,$0,28
jal		TAG_139
addi	$31,$31,4
addu	$31,$t0,$31
TAG_139:
addu	$31,$t2,$31
jal		TAG_140
sw		$31,-8192($31)
addi	$31,$31,4
TAG_140:
jalr	$31,$t3
addi	$31,$31,4
lw		$31,-12288($31)
TAG_141:
addu	$31,$31,$t0

la		$t3,TAG_144
addi	$31,$0,0
jal		TAG_142
addi	$31,$31,4
addu	$31,$t0,$31
TAG_142:
addu	$31,$t2,$31
jal		TAG_143
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_143:
jalr	$31,$t3
addu	$31,$31,$t0
addu	$31,$31,$t0
TAG_144:
beq		$31,$31,TAG_145
addu	$31,$31,$t0
addi	$31,$31,4
TAG_145:

la		$t3,TAG_148
addi	$31,$0,12
jal		TAG_146
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_146:
addu	$31,$t2,$31
jal		TAG_147
addi	$31,$31,4
addu	$31,$t0,$31
TAG_147:
jalr	$31,$t3
lw		$31,-12288($31)
sw		$31,4096($31)
TAG_148:
beq		$31,$31,TAG_149
addu	$31,$31,$t0
addu	$31,$t0,$31
TAG_149:

la		$t3,TAG_152
addi	$31,$0,16
jal		TAG_150
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_150:
addu	$31,$t2,$31
jal		TAG_151
addu	$31,$31,$t0
addu	$31,$31,$t0
TAG_151:
jalr	$31,$t3
addu	$31,$t0,$31
lw		$31,-12288($31)
TAG_152:
beq		$31,$0,TAG_153
lw		$31,-12288($31)
addi	$31,$31,4
TAG_153:

la		$t3,TAG_156
addi	$31,$0,8
jal		TAG_154
addi	$31,$31,4
addu	$31,$t0,$31
TAG_154:
addu	$31,$t2,$31
jal		TAG_155
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_155:
jalr	$31,$t3
addu	$31,$31,$t0
sw		$31,-8192($31)
TAG_156:
beq		$31,$0,TAG_157
addu	$31,$31,$t0
addu	$31,$31,$t0
TAG_157:

la		$t3,TAG_160
addi	$31,$0,12
jal		TAG_158
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_158:
addu	$31,$t2,$31
jal		TAG_159
addu	$31,$t0,$31
sw		$31,-8192($31)
TAG_159:
jalr	$31,$t3
addi	$31,$31,4
sw		$31,-8192($31)
TAG_160:
addi	$t1,$31,0
beq		$t1,$31,TAG_161
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_161:

la		$t3,TAG_164
addi	$31,$0,20
jal		TAG_162
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_162:
addu	$31,$t2,$31
jal		TAG_163
lw		$31,-12288($31)
sw		$31,4096($31)
TAG_163:
jalr	$31,$t3
addi	$31,$31,4
lw		$31,-12288($31)
TAG_164:
addi	$t1,$31,0
beq		$t1,$31,TAG_165
addi	$31,$31,4
lw		$31,-12288($31)
TAG_165:

la		$t3,TAG_168
addi	$31,$0,28
jal		TAG_166
addi	$31,$31,4
addu	$31,$31,$t0
TAG_166:
addu	$31,$t2,$31
jal		TAG_167
addi	$31,$31,4
addi	$31,$31,4
TAG_167:
jalr	$31,$t3
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_168:
addi	$t1,$31,1
beq		$31,$t1,TAG_169
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_169:

la		$t3,TAG_172
addi	$31,$0,12
jal		TAG_170
addu	$31,$t0,$31
lw		$31,-12288($31)
TAG_170:
addu	$31,$t2,$31
jal		TAG_171
lw		$31,-12288($31)
lw		$31,0($31)
TAG_171:
jalr	$31,$t3
sw		$31,-8192($31)
sw		$31,-8192($31)
TAG_172:
addi	$t1,$31,1
beq		$31,$t1,TAG_173
addi	$31,$31,4
lw		$31,-12288($31)
TAG_173:

la		$t3,TAG_176
addi	$31,$0,4
jal		TAG_174
addu	$31,$31,$t0
lw		$31,-12288($31)
TAG_174:
addu	$31,$t2,$31
jal		TAG_175
addu	$31,$t0,$31
lw		$31,-12288($31)
TAG_175:
jalr	$31,$t3
addu	$31,$t0,$31
addu	$31,$t0,$31
TAG_176:
addi	$31,$31,4

la		$t3,TAG_179
addi	$31,$0,8
jal		TAG_177
lw		$31,-12288($31)
addu	$31,$t0,$31
TAG_177:
addu	$31,$t0,$31
jal		TAG_178
lw		$31,-12288($31)
sw		$31,4096($31)
TAG_178:
jalr	$31,$t3
addi	$31,$31,4
addi	$31,$31,4
TAG_179:
addi	$31,$31,4

la		$t3,TAG_182
addi	$31,$0,12
jal		TAG_180
addu	$31,$t0,$31
sw		$31,-8192($31)
TAG_180:
addu	$31,$t2,$31
jal		TAG_181
addu	$31,$t0,$31
sw		$31,-8192($31)
TAG_181:
jalr	$31,$t3
addi	$31,$31,4
sw		$31,-8192($31)
TAG_182:
la		$31,TAG_183
jr		$31
addu	$31,$31,$t0
addu	$31,$t0,$31
TAG_183:

la		$t3,TAG_186
addi	$31,$0,24
jal		TAG_184
sw		$31,-8192($31)
addu	$31,$31,$t0
TAG_184:
addu	$31,$t2,$31
jal		TAG_185
sw		$31,-8192($31)
lw		$31,-12288($31)
TAG_185:
jalr	$31,$t3
addi	$31,$31,4
addu	$31,$31,$t0
TAG_186:
la		$31,TAG_187
jr		$31
sw		$31,-8192($31)
addu	$31,$t0,$31
TAG_187:

#--------------

addi	$t0,$0,2222
sw		$t0,2048($0)
addi	$t0,$0,3333
sw		$t0,2052($0)
addi	$t0,$0,4444
sw		$t0,2056($0)