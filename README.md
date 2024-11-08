# Practical-BE
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract bank{
    mapping(address=>uint) private balances;

    function getBalance() public view returns (uint){
        return balances[msg.sender];
    }

    function deposit() public payable {
        require(msg.value>0,"Deposit must be greater than 0");
        balances[msg.sender]+=msg.value;
    }

    function withdraw(uint amount) public
    {
        require(amount>0,"Withdraw must be greater than 0");
        require(amount<=balances[msg.sender],"Cannot withdraw more than you have;");

        balances[msg.sender]-=amount;
        payable (msg.sender).transfer(amount);
    }

}
