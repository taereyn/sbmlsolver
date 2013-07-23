/*
 * rrLLVMCodeGenBase.h
 *
 *  Created on: Jul 4, 2013
 *      Author: andy
 */

#ifndef LLVMCodeGenBaseH
#define LLVMCodeGenBaseH

#include "rrLLVMModelGeneratorContext.h"
#include "rrLLVMCodeGen.h"

namespace rr
{

/**
 * a convenience class to pull the vars out of a context, and
 * store them as ivars. It can get tedious alwasy typing mgc.getThis
 * and mgc.getThat. Furthermore, its faster to access them as ivars
 * as it does not incur a func call each time.
 */
class LLVMCodeGenBase : public LLVMSymbolResolver
{
public:
    using LLVMSymbolResolver::symbolValue;

protected:

    LLVMCodeGenBase(const LLVMModelGeneratorContext &mgc) :
            dataSymbols(mgc.getModelDataSymbols()),
            modelSymbols(mgc.getModelSymbols()),
            model(mgc.getModel()),
            context(mgc.getContext()),
            module(mgc.getModule()),
            builder(mgc.getBuilder()),
            engine(mgc.getExecutionEngine())
    {
    };

    /**
     * could potentially be null, everything else is guaranteed to be valid
     */
    const libsbml::Model *model;

    const LLVMModelDataSymbols &dataSymbols;
    const LLVMModelSymbols &modelSymbols;

    llvm::LLVMContext &context;
    llvm::Module *module;
    llvm::IRBuilder<> &builder;
    llvm::ExecutionEngine &engine;

    /**
     * The runtime resolution of symbols first search through the
     * replacement rules, applies them, them pulls the terminal
     * symbol values from the ModelData struct.
     *
     * The initial assigment generator overrides this and pulls
     * the terminal values from the initial values and assigments
     * specified in the model.
     */
    llvm::Value *symbolValue(const std::string& symbol, llvm::Value *modelData);

    virtual ~LLVMCodeGenBase() {};
};

} /* namespace rr */
#endif /* LLVMCodeGenBaseH */